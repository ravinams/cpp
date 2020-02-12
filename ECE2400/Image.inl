//========================================================================
// Image.inl
//========================================================================
// Implementations for inline functions for Image. This is for
// optimization purpose only. It is fine to leave this file empty.
//
// To inline a member function, simply use the inline keyword. For
// exmaple, to inline the get_ncols function, you need to put the
// definition of get_ncols in this file with the inline keyword like
// this:
//
// inline size_t Image::get_ncols() const
// {
//   ...
// }
//
// Think critically about which functions you want to inline! Note that
// inlining might HURT PERFORMANCE as it will cause your code to bloat.
// In other words, the executable size might be too big such that the
// system may spend most of its time fetching the next chunk of code from
// the disk.

inline size_t Image::get_ncols() const
{
	return m_cols ;
}
inline size_t Image::get_nrows() const
{ 
  	return m_rows ; 
}
inline void Image::set_label( char label )
{
  m_label= label ;
}
inline char Image::get_label() const
{
	return m_label ;
}