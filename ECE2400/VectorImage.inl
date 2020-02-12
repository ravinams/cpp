//========================================================================
// VectorImage.inl
//========================================================================
// Implementations for inline functions for VectorImage. This is for
// optimization purpose only. It is fine to leave this file empty.
//
// To inline a member function, simply use the inline keyword. For
// exmaple, to inline the [] operator, you need to put the definition of
// operator[] in this file with the inline keyword like this:
//
// inline Image VectorImage::operator[]( size_t idx ) const
// {
//   ...
// }
//
// Think critically about which functions you want to inline! Note that
// inlining might HURT PERFORMANCE as it will cause your code to bloat.
// In other words, the executable size might be too big such that the
// system may spend most of its time fetching the next chunk of code from
// the disk.

 inline Image VectorImage::operator[]( size_t idx ) const
 {
 	return m_arr[idx] ;
 }