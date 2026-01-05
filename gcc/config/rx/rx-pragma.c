#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "c-family/c-pragma.h"
#include "c-family/c-common.h"
#include "diagnostic-core.h"
#include "cpplib.h"
#include "hard-reg-set.h"
#include "output.h"
#include "rx-protos.h"
#include "function.h"
#define MAX_RECOG_OPERANDS 10
#include "reload.h"
#include "target.h"

/* Implements the "pragma ADDRESS" pragma.  This pragma takes a
 *    variable name and an address, and arranges for that variable to be
 *       "at" that address.  The variable is also made volatile.  */
static void
rx_pragma_address (cpp_reader * reader ATTRIBUTE_UNUSED)
{
  /* on off */
  tree var, addr;
  enum cpp_ttype type;

  type = pragma_lex (&var);
  if (type == CPP_NAME)
    {
      type = pragma_lex (&addr);
      if (type == CPP_NUMBER)
	{
	  if (var != error_mark_node)
	    {
	      unsigned uaddr = tree_to_uhwi (addr);
	      rx_note_pragma_address (IDENTIFIER_POINTER (var), uaddr);
	    }

	  type = pragma_lex (&var);
	  if (type != CPP_EOF)
	    {
	      error ("junk at end of #pragma ADDRESS");
	    }
	  return;
	}
    }
  error ("malformed #pragma ADDRESS variable address");
}

void
rx_register_pragmas (void)
{
  c_register_pragma (NULL, "ADDRESS", rx_pragma_address);
  c_register_pragma (NULL, "address", rx_pragma_address);
}
