/* ============================================================
* Falkon - Qt web browser
* Copyright (C) 2018 Anmol Gautam <tarptaeya@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#include "qmlmostvisitedurl.h"
#include <QQmlEngine>

QmlMostVisitedUrl::QmlMostVisitedUrl(const QString &title, const QString &url, QObject *parent)
    : QObject(parent)
    , m_title(title)
    , m_url(url)
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}

/**
 * @brief Get the title of the MostVisitedUrl item
 * @return String representing the title
 */
QString QmlMostVisitedUrl::title() const
{
    return m_title;
}

/**
 * @brief Get the url of the MostVisitedUrl item
 * @return String representing the url
 */
QString QmlMostVisitedUrl::url() const
{
    return m_url;
}

QmlMostVisitedUrlData::QmlMostVisitedUrlData()
{
}

QmlMostVisitedUrlData::~QmlMostVisitedUrlData()
{
    qDeleteAll(m_urls);
}

QmlMostVisitedUrl *QmlMostVisitedUrlData::get(const QString &title, const QString &url)
{
    QmlMostVisitedUrl *visitedUrl = m_urls.value({title, url});
    if (!visitedUrl) {
        visitedUrl = new QmlMostVisitedUrl(title, url);
        m_urls.insert({title, url}, visitedUrl);
    }
    return visitedUrl;
}