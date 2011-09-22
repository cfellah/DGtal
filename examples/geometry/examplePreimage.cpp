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
 * @file examplePreimage.cpp
 * @ingroup Examples
 * @author Tristan Roussillon (\c tristan.roussillon@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2011/09/21
 *
 * @brief An example file for Preimage2D.
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "ConfigExamples.h"

#include "DGtal/geometry/2d/Preimage2D.h"
#include "DGtal/geometry/2d/StraightLineFrom2Points.h"

///////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace DGtal;
using namespace Z2i; 


///////////////////////////////////////////////////////////////////////////////
int main( int argc, char** argv )
{
  trace.beginBlock ( "Example for Preimage computation" );
  trace.info() << "Args:";
  for ( int i = 0; i < argc; ++i )
    trace.info() << " " << argv[ i ];
  trace.info() << endl;
  
  std::string filename = examplesPath + "samples/DSS.dat";
  ifstream instream; // input stream
  instream.open (filename.c_str(), ifstream::in);
  
  Curve c; //grid curve
  c.initFromVectorStream(instream);

  trace.beginBlock("Simple preimage example");

  typedef StraightLineFrom2Points<Curve::KSpace::Integer> StraightLine;
  //! [PreimageTypedefFromStraightLine]
  typedef Preimage2D<StraightLine> Preimage2D;
  //! [PreimageTypedefFromStraightLine]


  //! [PreimageUsageFromIncidentPointsRange]
  Curve::IncidentPointsRange r = c.getIncidentPointsRange(); //range
  Curve::IncidentPointsRange::ConstIterator it (r.begin()); //iterators
  Curve::IncidentPointsRange::ConstIterator itEnd (r.end()); 

  //preimage computation
  Preimage2D thePreimage(it->first, it->second);
  ++it; 
  while ( (it != itEnd) &&
              (thePreimage.addFront(it->first, it->second)) )
  {
    ++it;
  }

  //display
  Board2D board;
  board.setUnit(Board2D::UCentimeter);
  board << r << thePreimage; 
  board.saveEPS( "PreimageExample.eps", Board2D::BoundingBox, 5000 );
  //! [PreimageUsageFromIncidentPointsRange]
  
  
  trace.endBlock();
  return 0;
}
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
