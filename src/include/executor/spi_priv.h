/*-------------------------------------------------------------------------
 *
 * spi.c
 *				Server Programming Interface private declarations
 *
 * $Header: /cvsroot/pgsql/src/include/executor/spi_priv.h,v 1.6 1999/07/15 15:21:14 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef SPI_PRIV_H
#define SPI_PRIV_H

#include "executor/spi.h"

typedef struct
{
	List	   *qtlist;
	uint32		processed;		/* by Executor */
	SPITupleTable *tuptable;
	Portal		portal;			/* portal per procedure */
	MemoryContext savedcxt;
	CommandId	savedId;
} _SPI_connection;

typedef struct
{
	List	   *qtlist;
	List	   *ptlist;
	int			nargs;
	Oid		   *argtypes;
} _SPI_plan;

#define _SPI_CPLAN_CURCXT	0
#define _SPI_CPLAN_PROCXT	1
#define _SPI_CPLAN_TOPCXT	2

#endif	 /* SPI_PRIV_H */
