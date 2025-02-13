// Copyright 2010-2020 wkhtmltopdf authors
// Copyright 2023-2024 Odoo S.A.
//
// This file is part of wkhtmltopdf.
//
// wkhtmltopdf is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// wkhtmltopdf is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with wkhtmltopdf.  If not, see <http://www.gnu.org/licenses/>.

#include <QDir>
#include <QFile>
#include <QUuid>

#include "tempfile.hh"
/*!
  \file tempfile.hh
  \brief Defines the TempFile class
*/

/*!
  \class TempFile
  \brief Class responsible for creating and deleting temporary files
*/
TempFile::TempFile() {
}

TempFile::~TempFile() {
	removeAll();
}

/*!
  \brief Create a new temporary file
  \param ext The extension of the temporary file
  \returns Path of the new temporary file
*/
QString TempFile::create(const QString & ext) {
	QString path = QDir::tempPath() + "/wktemp-" + QUuid::createUuid().toString().mid(1, 36) + ext;
	paths.append(path);
	return path;
}

/*!
  \brief Remove all the temporary files held by this object
*/
void TempFile::removeAll() {
	foreach (const QString & path, paths)
		QFile::remove(path);
	paths.clear();
}
