//=================================================================================================
/*!
//  \file blazetest/mathtest/creator/ZeroVector.h
//  \brief Specialization of the Creator class template for ZeroVector
//
//  Copyright (C) 2012-2020 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZETEST_MATHTEST_CREATOR_ZEROVECTOR_H_
#define _BLAZETEST_MATHTEST_CREATOR_ZEROVECTOR_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/ZeroVector.h>
#include <blazetest/mathtest/creator/Default.h>
#include <blazetest/system/Types.h>


namespace blazetest {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Specialization of the Creator class template for N-dimensional zero vectors.
//
// This specialization of the Creator class template is able to create random N-dimensional
// zero vectors.
*/
template< typename T  // Element type of the zero vector
        , bool TF >   // Transpose flag of the zero vector
class Creator< blaze::ZeroVector<T,TF> >
{
 public:
   //**Type definitions****************************************************************************
   using Type = blaze::ZeroVector<T,TF>;  //!< Type to be created by the Creator.
   //**********************************************************************************************

   //**Constructors********************************************************************************
   /*!\name Constructors */
   //@{
   explicit inline Creator();
   explicit inline Creator( size_t size );
   // No explicitly declared copy constructor.
   //@}
   //**********************************************************************************************

   //**Destructor**********************************************************************************
   // No explicitly declared destructor.
   //**********************************************************************************************

   //**Operators***********************************************************************************
   /*!\name Operators */
   //@{
   // No explicitly declared copy assignment operator.

   blaze::ZeroVector<T,TF> operator()() const;
   //@}
   //**********************************************************************************************

 private:
   //**Member variables****************************************************************************
   /*!\name Member variables */
   //@{
   size_t size_;  //!< The size for the zero vector.
   //@}
   //**********************************************************************************************
};
//*************************************************************************************************




//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the creator specialization for ZeroVector.
*/
template< typename T  // Element type of the zero vector
        , bool TF >   // Transpose flag of the zero vector
inline Creator< blaze::ZeroVector<T,TF> >::Creator()
   : size_( 3UL )  // The size for the zero vector
{}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Constructor for the creator specialization for ZeroVector.
//
// \param size The size for the zero vector.
*/
template< typename T  // Element type of the zero vector
        , bool TF >   // Transpose flag of the zero vector
inline Creator< blaze::ZeroVector<T,TF> >::Creator( size_t size )
   : size_( size )  // The size for the zero vector
{}
//*************************************************************************************************




//=================================================================================================
//
//  OPERATORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Returns a randomly created zero vector.
//
// \return The randomly generated zero vector.
*/
template< typename T  // Element type of the zero vector
        , bool TF >   // Transpose flag of the zero vector
inline blaze::ZeroVector<T,TF> Creator< blaze::ZeroVector<T,TF> >::operator()() const
{
   return blaze::ZeroVector<T,TF>( size_ );
}
//*************************************************************************************************

} // namespace blazetest

#endif
