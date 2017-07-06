/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

/**
 * @file testIndexedDigitalSurface.cpp
 * @ingroup Tests
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5127), University of Savoie, France
 *
 * @date 2017/02/06
 *
 * Functions for testing class IndexedDigitalSurface.
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include "DGtal/base/Common.h"
#include "ConfigTest.h"
#include "DGtalCatch.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/kernel/PointVector.h"
#include "DGtal/graph/CUndirectedSimpleGraph.h"
#include "DGtal/graph/BreadthFirstVisitor.h"
#include "DGtal/topology/DigitalSetBoundary.h"
#include "DGtal/shapes/Shapes.h"
#include "DGtal/shapes/IndexedDigitalSurface.h"
#include "DGtal/shapes/MeshHelpers.h"
///////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace DGtal;
using namespace Z3i;

///////////////////////////////////////////////////////////////////////////////
// Functions for testing class IndexedDigitalSurface.
///////////////////////////////////////////////////////////////////////////////


SCENARIO( "IndexedDigitalSurface< DigitalSetBoundary > build tests", "[idxdsurf][build]" )
{
  typedef DigitalSetBoundary< KSpace, DigitalSet > DigitalSurfaceContainer;
  typedef IndexedDigitalSurface< DigitalSurfaceContainer > DigSurface;
  Point p1( -5, -5, -5 );
  Point p2(  5,  5,  5 );
  KSpace K;
  K.init( p1, p2, true );
  DigitalSet aSet( Domain( p1, p2 ) );
  Shapes<Domain>::addNorm2Ball( aSet, Point( 0, 0, 0 ), 3 );
  DigSurface dsurf( new DigitalSurfaceContainer( K, aSet ) );
  GIVEN( "A digital set boundary over a ball of radius 3" ) {
    THEN( "The indexed digital surface has " ) {
      REQUIRE( dsurf.nbVertices() == 174 );
      REQUIRE( dsurf.nbEdges() == 348 );
      REQUIRE( dsurf.nbFaces() == 176 );
      REQUIRE( dsurf.Euler() == 2 );
    }
    THEN( "All vertices have 4 neighbors" ) {
      REQUIRE( dsurf.degree( 0 ) == 4 );
      REQUIRE( dsurf.degree( 17 ) == 4 );
      REQUIRE( dsurf.degree( 54) == 4 );
      REQUIRE( dsurf.degree( 102 ) == 4 );
    }
  }
}

SCENARIO( "IndexedDigitalSurface< RealPoint3 > concept check tests", "[idxdsurf][concepts]" )
{
  typedef DigitalSetBoundary< KSpace, DigitalSet > DigitalSurfaceContainer;
  typedef IndexedDigitalSurface< DigitalSurfaceContainer > DigSurface;
  BOOST_CONCEPT_ASSERT(( concepts::CUndirectedSimpleGraph< DigSurface > ));
}

/** @ingroup Tests **/
