/**
 * @licence app begin@
 * Copyright (C) 2014  BMW AG
 *
 * This file is part of GENIVI Project Dlt - Diagnostic Log and Trace console apps.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *
 * \author Alexander Wenzel <alexander.aw.wenzel@bmw.de> BMW 2011-2012
 *
 * \file dlt-example-user.c
 * For further information see http://www.genivi.org/.
 * @licence end@
 */


/*******************************************************************************
**                                                                            **
**  SRC-MODULE: example2.c                                                    **
**                                                                            **
**  TARGET    : linux                                                         **
**                                                                            **
**  PROJECT   : DLT                                                           **
**                                                                            **
**  AUTHOR    : Alexander Wenzel Alexander.AW.Wenzel@bmw.de                   **
**                                                                            **
**  PURPOSE   :                                                               **
**                                                                            **
**  REMARKS   :                                                               **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

#include <stdio.h>      /* for printf() and fprintf() */
#include <stdlib.h>     /* for atoi() and exit() */

#include <dlt.h>

#include "dlt_id.h"

DLT_DECLARE_CONTEXT(con_exa2);

int main()
{
	int num;

	DLT_REGISTER_APP("EXA2","Third Example");
	DLT_REGISTER_CONTEXT(con_exa2,"CON","First context");

	DLT_NONVERBOSE_MODE();

	for(num=0;num<10;num++)
	{
		DLT_LOG_ID(con_exa2,DLT_LOG_INFO,DLT_EXA2_CON_EXA2_ID1,DLT_INT32(12345678),DLT_STRING("Hello world 1!"));
		DLT_LOG_ID(con_exa2,DLT_LOG_ERROR,DLT_EXA2_CON_EXA2_ID2,DLT_INT32(87654321),DLT_STRING("Hello world 2!"));
		DLT_LOG_ID(con_exa2,DLT_LOG_WARN,DLT_EXA2_CON_EXA2_ID3,DLT_INT32(11223344),DLT_STRING("Hello world 3!"));
    	usleep(1000);
	}

	DLT_UNREGISTER_CONTEXT(con_exa2);

	DLT_UNREGISTER_APP();
}
