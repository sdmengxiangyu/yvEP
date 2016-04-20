#include "imagetransferdialog.h"
#include "ui_imagetransferdialog.h"

ImageTransferDialog::ImageTransferDialog(PluginManager *manager):ui(new Ui::ImageTransferDialog) {
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::WindowStaysOnTopHint);
    connect(manager,SIGNAL(RecvMsg(QString,QString)),this,SLOT(RecvMsg(QString,QString)));
    connect(this,SIGNAL(SendMsg(QString,QString)),manager,SIGNAL(SendMsg(QString,QString)));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(Transfer()));
}

ImageTransferDialog::~ImageTransferDialog() {
    delete ui;
}

void ImageTransferDialog::closeEvent(QCloseEvent *event) {
    event->ignore();
}

void ImageTransferDialog::RecvMsg(const QString &Nickname,const QString &Content) {
    if (Content.left(9)!="Image<!--")
        return;
    QPixmap Pixmap;
    Pixmap.loadFromData(QByteArray::fromBase64(Content.mid(9,Content.length()-12).toLocal8Bit()));
    ImageShowDialog *isd=new ImageShowDialog("Image from "+Nickname,Pixmap,this);
    isd->show();
}

void ImageTransferDialog::Transfer() {
    if (ui->lineEdit->text()=="") {
        QMessageBox::critical(this,"Error","Please enter a nickname");
        return;
    }
    QString Filename=QFileDialog::getOpenFileName(this,"Select an image");
    if (Filename=="")
        return;
    QPixmap Pixmap;
    if (Pixmap.load(Filename)) {
        QByteArray qba;
        QBuffer buffer(&qba);
        buffer.open(QIODevice::WriteOnly);
        Pixmap.save(&buffer,"PNG");
        emit SendMsg(ui->lineEdit->text(),"Image<!--"+qba.toBase64()+"-->");
    }
}
