#pragma once

/**
 * @file MetricAdjacency.h
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5807), University of Savoie, France
 *
 * @date 2010/07/04
 *
 * Header file for module MetricAdjacency.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(MetricAdjacency_RECURSES)
#error Recursive header files inclusion detected in MetricAdjacency.h
#else // defined(MetricAdjacency_RECURSES)
/** Prevents recursive inclusion of headers. */
#define MetricAdjacency_RECURSES

#if !defined MetricAdjacency_h
/** Prevents repeated inclusion of headers. */
#define MetricAdjacency_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/kernel/CSpace.h"
#include "DGtal/kernel/SpaceND.h"
#include "DGtal/kernel/BasicPointPredicates.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // template class MetricAdjacency
  /**
   * Description of template class 'MetricAdjacency' <p> \brief Aim:
   * Describes digital adjacencies in digital spaces that are defined
   * with the 1-norm and the infinity-norm.
   *
   * It induces the classical 4 and 8 adjacencies in 2D, the 6, 18 and
   * 26 adjacencies in 3D, and the \f$ \omega \f$ and \f$ \alpha \f$
   * adjacencies in nD.
   *
   * \b Model of a CAdjacency.
   *
   * @tparam TSpace any digital space (see concept CSpace).
   *
   * @tparam maxNorm1 defines which points are adjacent. More
   * precisely, two points are adjacent iff their norm-infinity is
   * less or equal than 1 and if their norm-1 is less or equal than
   * maxNorm1.
   *
   * @see testAdjacency.cpp
   */
  template <typename TSpace, std::size_t maxNorm1, 
	    std::size_t dimension = TSpace::staticDimension >
  class MetricAdjacency
  {
    BOOST_CONCEPT_ASSERT(( CSpace<TSpace> ));
    // ----------------------- public types ------------------------------
  public:
    // Required by CAdjacency
    typedef TSpace Space;
    typedef typename Space::Point Point;
    typedef MetricAdjacency<Space, maxNorm1, dimension> Adjacency;

    // Others
    typedef typename Space::Vector Vector;

    // ----------------------- Standard services ------------------------------
  public:

    /**
     * Constructor. Does nothing. Due to the symmetry and translation
     * invariance of this digital topology, all methods are static.
     */
    MetricAdjacency();

    /**
     * Destructor.
     */
    ~MetricAdjacency();

    // ----------------------- Adjacency services -----------------------------
  public:

    /**
     * @param p1 any point in this space.
     * @param p2 any point in this space.
     *
     * @return 'true' iff p1 is adjacent to p2 according to this
     * adjacency relation.
     */
    static
    bool isAdjacentTo( const Point & p1, const Point & p2 ); 

    /**
     * @param p1 any point in this space.
     * @param p2 any point in this space.
     *
     * @return 'true' iff p1 is adjacent to p2 according to this
     * adjacency relation and p1 != p2.
     */
    static
    bool isProperlyAdjacentTo( const Point & p1, const Point & p2 ); 

    /**
     * Outputs the whole neighborhood of point [p] satisfying the
     * given predicate as a sequence of *out_it++ = ...
     *
     * @tparam OutputIterator any output iterator (like
     * std::back_insert_iterator< std::vector<int> >).
     *
     * @tparam PointPredicate any predicate type.
     *
     * @param p any point of this space.
     * @param out_it any output iterator.
     * @param pred the predicate.
     */
    template <typename OutputIterator, 
	      typename PointPredicate>
    static
    void writeNeighborhood( const Point & p, 
			    OutputIterator & out_it,
			    const PointPredicate & pred );


    /**
     * Outputs the whole neighborhood of point [p] as a sequence of
     * *out_it++ = ...
     *
     * @tparam OutputIterator any output iterator (like
     * std::back_insert_iterator< std::vector<int> >).
     *
     * @param p any point of this space.
     * @param out_it any output iterator.
     */
    template <typename OutputIterator>
    static
    void writeNeighborhood( const Point & p, 
			    OutputIterator & out_it );

    /**
     * Outputs the whole neighborhood of point [p] (except p itself)
     * satisfying the given predicate as a sequence of *out_it++ = ...
     *
     * @tparam OutputIterator any output iterator (like
     * std::back_insert_iterator< std::vector<int> >).
     *
     * @tparam PointPredicate any predicate type.
     *
     * @param p any point of this space.
     * @param out_it any output iterator.
     * @param pred the predicate.
     */
    template <typename OutputIterator, 
	      typename PointPredicate >
    static
    void writeProperNeighborhood( const Point & p, 
				  OutputIterator & out_it,
				  const PointPredicate & pred );

    /**
     * Outputs the whole neighborhood of point [p] (except p itself)
     * as a sequence of *out_it++ = ...
     *
     * @tparam OutputIterator any output iterator (like
     * std::back_insert_iterator< std::vector<int> >).
     *
     * @param p any point of this space.
     * @param out_it any output iterator.
     */
    template <typename OutputIterator>
    static
    void writeProperNeighborhood( const Point & p, 
				  OutputIterator & out_it );
    
    // ----------------------- Interface --------------------------------------
  public:

    /**
     * Writes/Displays the object on an output stream.
     * @param out the output stream where the object is written.
     */
    static
    void selfDisplay ( std::ostream & out );

    /**
     * Checks the validity/consistency of the object.
     * @return 'true' if the object is valid, 'false' otherwise.
     */
    static
    bool isValid();

    // ------------------------- Protected Datas ------------------------------
  private:
    // ------------------------- Private Datas --------------------------------
  private:

    // ------------------------- Hidden services ------------------------------
  protected:


  private:

    /**
     * Copy constructor.
     * @param other the object to clone.
     * Forbidden by default.
     */
    MetricAdjacency ( const MetricAdjacency & other );

    /**
     * Assignment.
     * @param other the object to copy.
     * @return a reference on 'this'.
     * Forbidden by default.
     */
    MetricAdjacency & operator= ( const MetricAdjacency & other );

    // ------------------------- Internals ------------------------------------
  private:

  }; // end of class MetricAdjacency

  /**
   * Standard 4-neighborhood for a 2D digital space based on type 'int'.
   */
  typedef MetricAdjacency< SpaceND<int,2>, 1> Z2Adj4;

  /**
   * Standard 8-neighborhood for a 2D digital space based on type 'int'.
   */
  typedef MetricAdjacency< SpaceND<int,2>, 2> Z2Adj8;

  /**
   * Standard 6-neighborhood for a 3D digital space based on type 'int'.
   */
  typedef MetricAdjacency< SpaceND<int,3>, 1> Z3Adj6;

  /**
   * Standard 18-neighborhood for a 3D digital space based on type 'int'.
   */
  typedef MetricAdjacency< SpaceND<int,3>, 2> Z3Adj18;

  /**
   * Standard 26-neighborhood for a 3D digital space based on type 'int'.
   */
  typedef MetricAdjacency< SpaceND<int,3>, 3> Z3Adj26;

  /**
   * Overloads 'operator<<' for displaying objects of class 'MetricAdjacency'.
   * @param out the output stream where the object is written.
   * @param object the object of class 'MetricAdjacency' to write.
   * @return the output stream after the writing.
   */
  template <typename TSpace, std::size_t maxNorm1>
  std::ostream&
  operator<< ( std::ostream & out, 
	       const MetricAdjacency< TSpace,maxNorm1,
	       TSpace::staticDimension > & object );

} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#include "DGtal/topology/MetricAdjacency.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined MetricAdjacency_h

#undef MetricAdjacency_RECURSES
#endif // else defined(MetricAdjacency_RECURSES)