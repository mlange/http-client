static char RCS_Id[] = "$Id: moca.c,v 1.2 2001/11/01 22:08:37 mlange Exp $";
/*#START***********************************************************************
 *
 *  $Source: /cvs/les/moca/samples/http/cgi-bin/moca.c,v $
 *  $Revision: 1.2 $
 *  $Author: mlange $
 *
 *  Description: Sample client application that takes a hostname and port
 *               of a MOCA Connection Manager and a command to execute from
 *               stdin and then executes the given command, converts its
 *               result set to XML and dumps the XML to stdout.
 *
 *  $MOCA_Copyright-Start$
 *
 *  McHugh Open Component Architecture
 *  Copyright (c) 2001
 *  McHugh Software International
 *  All Rights Reserved
 *
 *  This software is furnished under a corporate license for use on a
 *  single computer system and can be copied (with inclusion of the
 *  above copyright) only for use on such a system.
 *
 *  The information in this document is subject to change without notice
 *  and should not be construed as a commitment by McHugh Software
 *  International.
 *
 *  McHugh Software International assumes no responsibility for the use of
 *  the software described in this document on equipment which has not been
 *  supplied or approved by McHugh Software International.
 *
 *  $MOCA_Copyright-End$
 *
 *#END************************************************************************/

#include <moca.h>

#include <stdio.h>
#include <stdlib.h>

#include <mocaerr.h>
#include <mocagendef.h>
#include <mislib.h>


int main(int argc, char **argv)
{
    char buffer[1024];
    misSocket *sock;

    sock = misSockOpen("shortline", 80);
    if (! sock)
    {
	printf("Could not connect to host\n");
	exit(1);
    }

    /*
    misSockPuts("POST /moca/cgi-bin/moca.exe", sock, "\n");
    misSockPuts("Content-Type: application/x-www-form-urlencoded", sock, "\n");
    misSockPuts("Content-Length: 49", sock, "\n\n");
    misSockPuts("host=localhost&port=9900&cmd=list+library+version", sock, "\n\n");
    */

    misSockFlush(sock);

    for (;;)
    {
        misSockGets(buffer, sizeof(buffer) - 1, sock, '\n');

        printf("%s", buffer);

	if (misSockEOF(sock))
	    break;
    }

    misSockClose(sock);

    exit(0);
}
