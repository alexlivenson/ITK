/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkRegistrationMapper.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#ifndef __itkRegistrationMapper_h
#define __itkRegistrationMapper_h

#include "itkObject.h"

namespace itk
{
  
/** \class RegistrationMapper
 * \brief Maps one object on the coordinate system of other.
 *
 * This Class is templated over the type of the mapped object
 * and over the type of the transformation used to convert the
 * coordinate system.
 *
 */

template <class TDomain, class TTransformation> 
class ITK_EXPORT RegistrationMapper : public Object 

{
public:
  /**
   * Standard "Self" typedef.
   */
  typedef RegistrationMapper  Self;

  /**
   * Standard "Superclass" typedef.
   */
  typedef Object  Superclass;

  /** 
   * Smart pointer typedef support 
   */
  typedef SmartPointer<Self>   Pointer;


  /**
   *  Type of the Domain
   */
  typedef TDomain            DomainType;


  /**
   *  Type of the Transformation
   */
  typedef TTransformation       TransformationType;
  

  /**
   *  Pointer type for the Reference 
   */
  typedef typename DomainType::Pointer DomainPointer;


  /**
   *  Pointer type for the Transformation
   */
  typedef typename TransformationType::Pointer TransformationPointer;


  /** 
   * Run-time type information (and related methods).
   */
  itkTypeMacro(RegistrationMapper, Object);


  /**
   * Method for creation through the object factory.
   */
  itkNewMacro(Self);
  


  /**
   * Connect the Domain
   */
   void SetDomain( DomainType * );


  /**
   * Connect the Transformation
   */
   void SetTransformation( TransformationType * );


  
protected:

  DomainPointer            m_Domain;
  TransformationPointer    m_Transformation;

  RegistrationMapper();
  virtual ~RegistrationMapper() {};
  RegistrationMapper(const Self&) {}
  void operator=(const Self&) {}


};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkRegistrationMapper.txx"
#endif

#endif



