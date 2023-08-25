/*
 * coreHTTP v3.0.0
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file httpParserOnStatusCallback_harness.c
 * @brief Implements the proof harness for httpParserOnStatusCallback function.
 */

#include "core_http_client.h"
#include "http_cbmc_state.h"
#include "llhttp.h"

int __CPROVER_file_local_core_http_client_c_httpParserOnStatusCallback( llhttp_t * pHttpParser,
                                                                        const char * pLoc,
                                                                        size_t length );

void httpParserOnStatusCallback_harness()
{
    llhttp_t * pHttpParser;
    HTTPParsingContext_t * pParsingContext;
    HTTPResponse_t * pResponse;
    size_t length, locOffset;
    char * pLoc;

    pHttpParser = allocateHttpSendParser( NULL );

    pParsingContext = ( HTTPParsingContext_t * ) pHttpParser->data;

    pResponse = pParsingContext->pResponse;
    __CPROVER_assume( locOffset <= pResponse->bufferLen );
    __CPROVER_assume( length <= pResponse->bufferLen - locOffset );
    pLoc = pResponse->pBuffer + locOffset;

    __CPROVER_file_local_core_http_client_c_httpParserOnStatusCallback(
        pHttpParser,
        pLoc,
        length );
}
