// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com
// Original code is licensed as follows:
/*
 * Copyright 2013 ZXing authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "barcode.h"
#include "include/BC_PDF417Codeword.h"
FX_INT32 CBC_Codeword::BARCODE_ROW_UNKNOWN = -1;
CBC_Codeword::CBC_Codeword(FX_INT32 startX, FX_INT32 endX, FX_INT32 bucket, FX_INT32 cvalue)
{
    m_startX = startX;
    m_endX = endX;
    m_bucket = bucket;
    m_value = cvalue;
    m_rowNumber = BARCODE_ROW_UNKNOWN;
}
CBC_Codeword::~CBC_Codeword()
{
}
FX_BOOL CBC_Codeword::hasValidRowNumber()
{
    return isValidRowNumber(m_rowNumber);
}
FX_BOOL CBC_Codeword::isValidRowNumber(FX_INT32 rowNumber)
{
    return m_rowNumber != BARCODE_ROW_UNKNOWN && m_bucket == (m_rowNumber % 3) * 3;
}
void CBC_Codeword::setRowNumberAsRowIndicatorColumn()
{
    m_rowNumber = (m_value / 30) * 3 + m_bucket / 3;
}
FX_INT32 CBC_Codeword::getWidth()
{
    return m_endX - m_startX;
}
FX_INT32 CBC_Codeword::getStartX()
{
    return m_startX;
}
FX_INT32 CBC_Codeword::getEndX()
{
    return m_endX;
}
FX_INT32 CBC_Codeword::getBucket()
{
    return m_bucket;
}
FX_INT32 CBC_Codeword::getValue()
{
    return m_value;
}
FX_INT32 CBC_Codeword::getRowNumber()
{
    return m_rowNumber;
}
void CBC_Codeword::setRowNumber(FX_INT32 rowNumber)
{
    m_rowNumber = rowNumber;
}
CFX_ByteString CBC_Codeword::toString()
{
    return m_rowNumber + (FX_CHAR)'|' + m_value;
}
