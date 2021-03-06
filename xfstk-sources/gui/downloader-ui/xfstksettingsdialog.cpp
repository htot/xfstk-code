#include "xfstksettingsdialog.h"
#include "ui_xfstksettingsdialog.h"

/*
    Copyright (C) 2015  Intel Corporation

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

XfstkSettingsDialog::XfstkSettingsDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::XfstkSettingsDialog)
{
    ui->setupUi(this);
}

XfstkSettingsDialog::~XfstkSettingsDialog()
{
    delete ui;
}

QTabWidget *XfstkSettingsDialog::GetOptionsInterfaceTabDock()
{
    return this->ui->OptionInterfaceTabDock;
}

void XfstkSettingsDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void XfstkSettingsDialog::CurrentTabChanged(int index)
{
    this->ui->OptionInterfaceTabDock->setTabEnabled(index, true);
    this->ui->OptionInterfaceTabDock->setCurrentIndex(index);
    for(int i = 0; i < this->ui->OptionInterfaceTabDock->count(); i++) {
        if(i == index) {
            continue;
        }
        else {
            this->ui->OptionInterfaceTabDock->setTabEnabled(i, false);
        }
    }
}
