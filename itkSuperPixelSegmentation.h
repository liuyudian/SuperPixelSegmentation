#ifndef __itkSuperPixelSegmentation_h
#define __itkSuperPixelSegmentation_h

#include "itkImageToImageFilter.h"

namespace itk
{
template< typename TInputImage, typename TOutputImage>
class SuperPixelSegmentation : public ImageToImageFilter< TInputImage, TOutputImage >
{
public:
  /** Standard class typedefs. */
  typedef SuperPixelSegmentation Self;
  typedef ImageToImageFilter< TInputImage, TOutputImage > Superclass;
  typedef SmartPointer< Self >        Pointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(SuperPixelSegmentation, ImageToImageFilter);

  itkSetMacro( MinSize, int );
  itkGetMacro( MinSize, int);

  itkSetMacro( K, float );
  itkGetMacro( K, float);

  itkSetMacro( Sigma, float );
  itkGetMacro( Sigma, float);
  
protected:
  SuperPixelSegmentation(){}
  ~SuperPixelSegmentation(){}

  /** Does the real work. */
  virtual void GenerateData();

private:
  SuperPixelSegmentation(const Self &); //purposely not implemented
  void operator=(const Self &);  //purposely not implemented

  int m_MinSize;
  float m_K;
  float m_Sigma;
};
} //namespace ITK

#include "itkSuperPixelSegmentation.hxx"

#endif