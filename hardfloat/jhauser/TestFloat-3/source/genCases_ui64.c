
/*
===============================================================================

This C source file is part of TestFloat, Release 2a, a package of programs
for testing the correctness of floating-point arithmetic complying to the
IEC/IEEE Standard for Floating-Point.

Written by John R. Hauser.  More information is available through the Web
page `http://HTTP.CS.Berkeley.EDU/~jhauser/arithmetic/TestFloat.html'.

THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort
has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT
TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO
PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY
AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.

Derivative works are acceptable, even for commercial purposes, so long as
(1) they include prominent notice that the work is derivative, and (2) they
include prominent notice akin to these four paragraphs for those parts of
this code that are retained.

===============================================================================
*/

#include <stdbool.h>
#include <stdint.h>
#include "random.h"
#include "genCases.h"

struct sequence {
    int term1Num, term2Num;
    bool done;
};

enum { ui64NumP1 = 252 };
static const uint64_t ui64P1[ ui64NumP1 ] = {
    UINT64_C( 0x0000000000000000 ),
    UINT64_C( 0x0000000000000001 ),
    UINT64_C( 0x0000000000000002 ),
    UINT64_C( 0x0000000000000004 ),
    UINT64_C( 0x0000000000000008 ),
    UINT64_C( 0x0000000000000010 ),
    UINT64_C( 0x0000000000000020 ),
    UINT64_C( 0x0000000000000040 ),
    UINT64_C( 0x0000000000000080 ),
    UINT64_C( 0x0000000000000100 ),
    UINT64_C( 0x0000000000000200 ),
    UINT64_C( 0x0000000000000400 ),
    UINT64_C( 0x0000000000000800 ),
    UINT64_C( 0x0000000000001000 ),
    UINT64_C( 0x0000000000002000 ),
    UINT64_C( 0x0000000000004000 ),
    UINT64_C( 0x0000000000008000 ),
    UINT64_C( 0x0000000000010000 ),
    UINT64_C( 0x0000000000020000 ),
    UINT64_C( 0x0000000000040000 ),
    UINT64_C( 0x0000000000080000 ),
    UINT64_C( 0x0000000000100000 ),
    UINT64_C( 0x0000000000200000 ),
    UINT64_C( 0x0000000000400000 ),
    UINT64_C( 0x0000000000800000 ),
    UINT64_C( 0x0000000001000000 ),
    UINT64_C( 0x0000000002000000 ),
    UINT64_C( 0x0000000004000000 ),
    UINT64_C( 0x0000000008000000 ),
    UINT64_C( 0x0000000010000000 ),
    UINT64_C( 0x0000000020000000 ),
    UINT64_C( 0x0000000040000000 ),
    UINT64_C( 0x0000000080000000 ),
    UINT64_C( 0x0000000100000000 ),
    UINT64_C( 0x0000000200000000 ),
    UINT64_C( 0x0000000400000000 ),
    UINT64_C( 0x0000000800000000 ),
    UINT64_C( 0x0000001000000000 ),
    UINT64_C( 0x0000002000000000 ),
    UINT64_C( 0x0000004000000000 ),
    UINT64_C( 0x0000008000000000 ),
    UINT64_C( 0x0000010000000000 ),
    UINT64_C( 0x0000020000000000 ),
    UINT64_C( 0x0000040000000000 ),
    UINT64_C( 0x0000080000000000 ),
    UINT64_C( 0x0000100000000000 ),
    UINT64_C( 0x0000200000000000 ),
    UINT64_C( 0x0000400000000000 ),
    UINT64_C( 0x0000800000000000 ),
    UINT64_C( 0x0001000000000000 ),
    UINT64_C( 0x0002000000000000 ),
    UINT64_C( 0x0004000000000000 ),
    UINT64_C( 0x0008000000000000 ),
    UINT64_C( 0x0010000000000000 ),
    UINT64_C( 0x0020000000000000 ),
    UINT64_C( 0x0040000000000000 ),
    UINT64_C( 0x0080000000000000 ),
    UINT64_C( 0x0100000000000000 ),
    UINT64_C( 0x0200000000000000 ),
    UINT64_C( 0x0400000000000000 ),
    UINT64_C( 0x0800000000000000 ),
    UINT64_C( 0x1000000000000000 ),
    UINT64_C( 0x2000000000000000 ),
    UINT64_C( 0x4000000000000000 ),
    UINT64_C( 0x8000000000000000 ),
    UINT64_C( 0xC000000000000000 ),
    UINT64_C( 0xE000000000000000 ),
    UINT64_C( 0xF000000000000000 ),
    UINT64_C( 0xF800000000000000 ),
    UINT64_C( 0xFC00000000000000 ),
    UINT64_C( 0xFE00000000000000 ),
    UINT64_C( 0xFF00000000000000 ),
    UINT64_C( 0xFF80000000000000 ),
    UINT64_C( 0xFFC0000000000000 ),
    UINT64_C( 0xFFE0000000000000 ),
    UINT64_C( 0xFFF0000000000000 ),
    UINT64_C( 0xFFF8000000000000 ),
    UINT64_C( 0xFFFC000000000000 ),
    UINT64_C( 0xFFFE000000000000 ),
    UINT64_C( 0xFFFF000000000000 ),
    UINT64_C( 0xFFFF800000000000 ),
    UINT64_C( 0xFFFFC00000000000 ),
    UINT64_C( 0xFFFFE00000000000 ),
    UINT64_C( 0xFFFFF00000000000 ),
    UINT64_C( 0xFFFFF80000000000 ),
    UINT64_C( 0xFFFFFC0000000000 ),
    UINT64_C( 0xFFFFFE0000000000 ),
    UINT64_C( 0xFFFFFF0000000000 ),
    UINT64_C( 0xFFFFFF8000000000 ),
    UINT64_C( 0xFFFFFFC000000000 ),
    UINT64_C( 0xFFFFFFE000000000 ),
    UINT64_C( 0xFFFFFFF000000000 ),
    UINT64_C( 0xFFFFFFF800000000 ),
    UINT64_C( 0xFFFFFFFC00000000 ),
    UINT64_C( 0xFFFFFFFE00000000 ),
    UINT64_C( 0xFFFFFFFF00000000 ),
    UINT64_C( 0xFFFFFFFF80000000 ),
    UINT64_C( 0xFFFFFFFFC0000000 ),
    UINT64_C( 0xFFFFFFFFE0000000 ),
    UINT64_C( 0xFFFFFFFFF0000000 ),
    UINT64_C( 0xFFFFFFFFF8000000 ),
    UINT64_C( 0xFFFFFFFFFC000000 ),
    UINT64_C( 0xFFFFFFFFFE000000 ),
    UINT64_C( 0xFFFFFFFFFF000000 ),
    UINT64_C( 0xFFFFFFFFFF800000 ),
    UINT64_C( 0xFFFFFFFFFFC00000 ),
    UINT64_C( 0xFFFFFFFFFFE00000 ),
    UINT64_C( 0xFFFFFFFFFFF00000 ),
    UINT64_C( 0xFFFFFFFFFFF80000 ),
    UINT64_C( 0xFFFFFFFFFFFC0000 ),
    UINT64_C( 0xFFFFFFFFFFFE0000 ),
    UINT64_C( 0xFFFFFFFFFFFF0000 ),
    UINT64_C( 0xFFFFFFFFFFFF8000 ),
    UINT64_C( 0xFFFFFFFFFFFFC000 ),
    UINT64_C( 0xFFFFFFFFFFFFE000 ),
    UINT64_C( 0xFFFFFFFFFFFFF000 ),
    UINT64_C( 0xFFFFFFFFFFFFF800 ),
    UINT64_C( 0xFFFFFFFFFFFFFC00 ),
    UINT64_C( 0xFFFFFFFFFFFFFE00 ),
    UINT64_C( 0xFFFFFFFFFFFFFF00 ),
    UINT64_C( 0xFFFFFFFFFFFFFF80 ),
    UINT64_C( 0xFFFFFFFFFFFFFFC0 ),
    UINT64_C( 0xFFFFFFFFFFFFFFE0 ),
    UINT64_C( 0xFFFFFFFFFFFFFFF0 ),
    UINT64_C( 0xFFFFFFFFFFFFFFF8 ),
    UINT64_C( 0xFFFFFFFFFFFFFFFC ),
    UINT64_C( 0xFFFFFFFFFFFFFFFE ),
    UINT64_C( 0xFFFFFFFFFFFFFFFF ),
    UINT64_C( 0xFFFFFFFFFFFFFFFD ),
    UINT64_C( 0xFFFFFFFFFFFFFFFB ),
    UINT64_C( 0xFFFFFFFFFFFFFFF7 ),
    UINT64_C( 0xFFFFFFFFFFFFFFEF ),
    UINT64_C( 0xFFFFFFFFFFFFFFDF ),
    UINT64_C( 0xFFFFFFFFFFFFFFBF ),
    UINT64_C( 0xFFFFFFFFFFFFFF7F ),
    UINT64_C( 0xFFFFFFFFFFFFFEFF ),
    UINT64_C( 0xFFFFFFFFFFFFFDFF ),
    UINT64_C( 0xFFFFFFFFFFFFFBFF ),
    UINT64_C( 0xFFFFFFFFFFFFF7FF ),
    UINT64_C( 0xFFFFFFFFFFFFEFFF ),
    UINT64_C( 0xFFFFFFFFFFFFDFFF ),
    UINT64_C( 0xFFFFFFFFFFFFBFFF ),
    UINT64_C( 0xFFFFFFFFFFFF7FFF ),
    UINT64_C( 0xFFFFFFFFFFFEFFFF ),
    UINT64_C( 0xFFFFFFFFFFFDFFFF ),
    UINT64_C( 0xFFFFFFFFFFFBFFFF ),
    UINT64_C( 0xFFFFFFFFFFF7FFFF ),
    UINT64_C( 0xFFFFFFFFFFEFFFFF ),
    UINT64_C( 0xFFFFFFFFFFDFFFFF ),
    UINT64_C( 0xFFFFFFFFFFBFFFFF ),
    UINT64_C( 0xFFFFFFFFFF7FFFFF ),
    UINT64_C( 0xFFFFFFFFFEFFFFFF ),
    UINT64_C( 0xFFFFFFFFFDFFFFFF ),
    UINT64_C( 0xFFFFFFFFFBFFFFFF ),
    UINT64_C( 0xFFFFFFFFF7FFFFFF ),
    UINT64_C( 0xFFFFFFFFEFFFFFFF ),
    UINT64_C( 0xFFFFFFFFDFFFFFFF ),
    UINT64_C( 0xFFFFFFFFBFFFFFFF ),
    UINT64_C( 0xFFFFFFFF7FFFFFFF ),
    UINT64_C( 0xFFFFFFFEFFFFFFFF ),
    UINT64_C( 0xFFFFFFFDFFFFFFFF ),
    UINT64_C( 0xFFFFFFFBFFFFFFFF ),
    UINT64_C( 0xFFFFFFF7FFFFFFFF ),
    UINT64_C( 0xFFFFFFEFFFFFFFFF ),
    UINT64_C( 0xFFFFFFDFFFFFFFFF ),
    UINT64_C( 0xFFFFFFBFFFFFFFFF ),
    UINT64_C( 0xFFFFFF7FFFFFFFFF ),
    UINT64_C( 0xFFFFFEFFFFFFFFFF ),
    UINT64_C( 0xFFFFFDFFFFFFFFFF ),
    UINT64_C( 0xFFFFFBFFFFFFFFFF ),
    UINT64_C( 0xFFFFF7FFFFFFFFFF ),
    UINT64_C( 0xFFFFEFFFFFFFFFFF ),
    UINT64_C( 0xFFFFDFFFFFFFFFFF ),
    UINT64_C( 0xFFFFBFFFFFFFFFFF ),
    UINT64_C( 0xFFFF7FFFFFFFFFFF ),
    UINT64_C( 0xFFFEFFFFFFFFFFFF ),
    UINT64_C( 0xFFFDFFFFFFFFFFFF ),
    UINT64_C( 0xFFFBFFFFFFFFFFFF ),
    UINT64_C( 0xFFF7FFFFFFFFFFFF ),
    UINT64_C( 0xFFEFFFFFFFFFFFFF ),
    UINT64_C( 0xFFDFFFFFFFFFFFFF ),
    UINT64_C( 0xFFBFFFFFFFFFFFFF ),
    UINT64_C( 0xFF7FFFFFFFFFFFFF ),
    UINT64_C( 0xFEFFFFFFFFFFFFFF ),
    UINT64_C( 0xFDFFFFFFFFFFFFFF ),
    UINT64_C( 0xFBFFFFFFFFFFFFFF ),
    UINT64_C( 0xF7FFFFFFFFFFFFFF ),
    UINT64_C( 0xEFFFFFFFFFFFFFFF ),
    UINT64_C( 0xDFFFFFFFFFFFFFFF ),
    UINT64_C( 0xBFFFFFFFFFFFFFFF ),
    UINT64_C( 0x7FFFFFFFFFFFFFFF ),
    UINT64_C( 0x3FFFFFFFFFFFFFFF ),
    UINT64_C( 0x1FFFFFFFFFFFFFFF ),
    UINT64_C( 0x0FFFFFFFFFFFFFFF ),
    UINT64_C( 0x07FFFFFFFFFFFFFF ),
    UINT64_C( 0x03FFFFFFFFFFFFFF ),
    UINT64_C( 0x01FFFFFFFFFFFFFF ),
    UINT64_C( 0x00FFFFFFFFFFFFFF ),
    UINT64_C( 0x007FFFFFFFFFFFFF ),
    UINT64_C( 0x003FFFFFFFFFFFFF ),
    UINT64_C( 0x001FFFFFFFFFFFFF ),
    UINT64_C( 0x000FFFFFFFFFFFFF ),
    UINT64_C( 0x0007FFFFFFFFFFFF ),
    UINT64_C( 0x0003FFFFFFFFFFFF ),
    UINT64_C( 0x0001FFFFFFFFFFFF ),
    UINT64_C( 0x0000FFFFFFFFFFFF ),
    UINT64_C( 0x00007FFFFFFFFFFF ),
    UINT64_C( 0x00003FFFFFFFFFFF ),
    UINT64_C( 0x00001FFFFFFFFFFF ),
    UINT64_C( 0x00000FFFFFFFFFFF ),
    UINT64_C( 0x000007FFFFFFFFFF ),
    UINT64_C( 0x000003FFFFFFFFFF ),
    UINT64_C( 0x000001FFFFFFFFFF ),
    UINT64_C( 0x000000FFFFFFFFFF ),
    UINT64_C( 0x0000007FFFFFFFFF ),
    UINT64_C( 0x0000003FFFFFFFFF ),
    UINT64_C( 0x0000001FFFFFFFFF ),
    UINT64_C( 0x0000000FFFFFFFFF ),
    UINT64_C( 0x00000007FFFFFFFF ),
    UINT64_C( 0x00000003FFFFFFFF ),
    UINT64_C( 0x00000001FFFFFFFF ),
    UINT64_C( 0x00000000FFFFFFFF ),
    UINT64_C( 0x000000007FFFFFFF ),
    UINT64_C( 0x000000003FFFFFFF ),
    UINT64_C( 0x000000001FFFFFFF ),
    UINT64_C( 0x000000000FFFFFFF ),
    UINT64_C( 0x0000000007FFFFFF ),
    UINT64_C( 0x0000000003FFFFFF ),
    UINT64_C( 0x0000000001FFFFFF ),
    UINT64_C( 0x0000000000FFFFFF ),
    UINT64_C( 0x00000000007FFFFF ),
    UINT64_C( 0x00000000003FFFFF ),
    UINT64_C( 0x00000000001FFFFF ),
    UINT64_C( 0x00000000000FFFFF ),
    UINT64_C( 0x000000000007FFFF ),
    UINT64_C( 0x000000000003FFFF ),
    UINT64_C( 0x000000000001FFFF ),
    UINT64_C( 0x000000000000FFFF ),
    UINT64_C( 0x0000000000007FFF ),
    UINT64_C( 0x0000000000003FFF ),
    UINT64_C( 0x0000000000001FFF ),
    UINT64_C( 0x0000000000000FFF ),
    UINT64_C( 0x00000000000007FF ),
    UINT64_C( 0x00000000000003FF ),
    UINT64_C( 0x00000000000001FF ),
    UINT64_C( 0x00000000000000FF ),
    UINT64_C( 0x000000000000007F ),
    UINT64_C( 0x000000000000003F ),
    UINT64_C( 0x000000000000001F ),
    UINT64_C( 0x000000000000000F ),
    UINT64_C( 0x0000000000000007 ),
    UINT64_C( 0x0000000000000003 )
};

static uint_fast64_t ui64NextP1( struct sequence *sequencePtr )
{
    int termNum;
    uint_fast64_t z;

    termNum = sequencePtr->term1Num;
    z = ui64P1[ termNum ];
    ++termNum;
    if ( ui64NumP1 <= termNum ) {
        termNum = 0;
        sequencePtr->done = true;
    }
    sequencePtr->term1Num = termNum;
    return z;

}

static const uint_fast64_t ui64NumP2 =
    ( ui64NumP1 * ui64NumP1 + ui64NumP1 ) / 2;

static uint_fast64_t ui64NextP2( struct sequence *sequencePtr )
{
    int term1Num, term2Num;
    uint_fast64_t z;

    term2Num = sequencePtr->term2Num;
    term1Num = sequencePtr->term1Num;
    z = ui64P1[ term1Num ] + ui64P1[ term2Num ];
    ++term2Num;
    if ( ui64NumP1 <= term2Num ) {
        ++term1Num;
        if ( ui64NumP1 <= term1Num ) {
            term1Num = 0;
            sequencePtr->done = true;
        }
        term2Num = term1Num;
        sequencePtr->term1Num = term1Num;
    }
    sequencePtr->term2Num = term2Num;
    return z;

}

static uint_fast64_t ui64RandomP3( void )
{

    return
          ui64P1[ random_ui8() % ui64NumP1 ]
        + ui64P1[ random_ui8() % ui64NumP1 ]
        + ui64P1[ random_ui8() % ui64NumP1 ];

}

enum { ui64NumPInfWeightMasks = 61 };
static const uint64_t ui64PInfWeightMasks[ ui64NumPInfWeightMasks ] = {
    UINT64_C( 0xFFFFFFFFFFFFFFFF ),
    UINT64_C( 0x7FFFFFFFFFFFFFFF ),
    UINT64_C( 0x3FFFFFFFFFFFFFFF ),
    UINT64_C( 0x1FFFFFFFFFFFFFFF ),
    UINT64_C( 0x0FFFFFFFFFFFFFFF ),
    UINT64_C( 0x07FFFFFFFFFFFFFF ),
    UINT64_C( 0x03FFFFFFFFFFFFFF ),
    UINT64_C( 0x01FFFFFFFFFFFFFF ),
    UINT64_C( 0x00FFFFFFFFFFFFFF ),
    UINT64_C( 0x007FFFFFFFFFFFFF ),
    UINT64_C( 0x003FFFFFFFFFFFFF ),
    UINT64_C( 0x001FFFFFFFFFFFFF ),
    UINT64_C( 0x000FFFFFFFFFFFFF ),
    UINT64_C( 0x0007FFFFFFFFFFFF ),
    UINT64_C( 0x0003FFFFFFFFFFFF ),
    UINT64_C( 0x0001FFFFFFFFFFFF ),
    UINT64_C( 0x0000FFFFFFFFFFFF ),
    UINT64_C( 0x00007FFFFFFFFFFF ),
    UINT64_C( 0x00003FFFFFFFFFFF ),
    UINT64_C( 0x00001FFFFFFFFFFF ),
    UINT64_C( 0x00000FFFFFFFFFFF ),
    UINT64_C( 0x000007FFFFFFFFFF ),
    UINT64_C( 0x000003FFFFFFFFFF ),
    UINT64_C( 0x000001FFFFFFFFFF ),
    UINT64_C( 0x000000FFFFFFFFFF ),
    UINT64_C( 0x0000007FFFFFFFFF ),
    UINT64_C( 0x0000003FFFFFFFFF ),
    UINT64_C( 0x0000001FFFFFFFFF ),
    UINT64_C( 0x0000000FFFFFFFFF ),
    UINT64_C( 0x00000007FFFFFFFF ),
    UINT64_C( 0x00000003FFFFFFFF ),
    UINT64_C( 0x00000001FFFFFFFF ),
    UINT64_C( 0x00000000FFFFFFFF ),
    UINT64_C( 0x000000007FFFFFFF ),
    UINT64_C( 0x000000003FFFFFFF ),
    UINT64_C( 0x000000001FFFFFFF ),
    UINT64_C( 0x000000000FFFFFFF ),
    UINT64_C( 0x0000000007FFFFFF ),
    UINT64_C( 0x0000000003FFFFFF ),
    UINT64_C( 0x0000000001FFFFFF ),
    UINT64_C( 0x0000000000FFFFFF ),
    UINT64_C( 0x00000000007FFFFF ),
    UINT64_C( 0x00000000003FFFFF ),
    UINT64_C( 0x00000000001FFFFF ),
    UINT64_C( 0x00000000000FFFFF ),
    UINT64_C( 0x000000000007FFFF ),
    UINT64_C( 0x000000000003FFFF ),
    UINT64_C( 0x000000000001FFFF ),
    UINT64_C( 0x000000000000FFFF ),
    UINT64_C( 0x0000000000007FFF ),
    UINT64_C( 0x0000000000003FFF ),
    UINT64_C( 0x0000000000001FFF ),
    UINT64_C( 0x0000000000000FFF ),
    UINT64_C( 0x00000000000007FF ),
    UINT64_C( 0x00000000000003FF ),
    UINT64_C( 0x00000000000001FF ),
    UINT64_C( 0x00000000000000FF ),
    UINT64_C( 0x000000000000007F ),
    UINT64_C( 0x000000000000003F ),
    UINT64_C( 0x000000000000001F ),
    UINT64_C( 0x000000000000000F )
};

static uint_fast64_t ui64RandomPInf( void )
{
    int weightMaskNum;

    weightMaskNum = random_ui8() % ui64NumPInfWeightMasks;
    return random_ui64() & ui64PInfWeightMasks[ weightMaskNum ];

}

static struct sequence sequenceA;
static int subcase;

uint_fast64_t genCases_ui64_a;

void genCases_ui64_a_init( void )
{

    sequenceA.term2Num = 0;
    sequenceA.term1Num = 0;
    sequenceA.done = false;
    subcase = 0;
    genCases_total = ( genCases_level == 1 ) ? 3 * ui64NumP1 : 2 * ui64NumP2;
    genCases_done = false;

}

void genCases_ui64_a_next( void )
{

    if ( genCases_level == 1 ) {
        switch ( subcase ) {
         case 0:
            genCases_ui64_a = ui64RandomP3();
            break;
         case 1:
            genCases_ui64_a = ui64RandomPInf();
            break;
         case 2:
            genCases_ui64_a = ui64NextP1( &sequenceA );
            genCases_done = sequenceA.done;
            subcase = -1;
            break;
        }
    } else {
        switch ( subcase ) {
         case 0:
            genCases_ui64_a = ui64RandomP3();
            break;
         case 2:
            genCases_ui64_a = ui64RandomPInf();
            break;
         case 3:
            subcase = -1;
         case 1:
            genCases_ui64_a = ui64NextP2( &sequenceA );
            genCases_done = sequenceA.done;
            break;
        }
    }
    ++subcase;

}

