#ifndef MATRIX_H
#define MATRIX_H

namespace Templates
{
template <typename T>
class TMatrix
{
    std::vector<T> m_ObjectElements;
    unsigned int m_Rows;
    unsigned int m_Columns;
public:
    TMatrix(unsigned int rows, unsigned int columns) : m_Rows(rows), m_Columns(columns)
    {
            m_ObjectElements.resize(m_Rows * m_Columns);
    }

    T& operator()(unsigned int x, unsigned int y)
    {
            if (x >= m_Rows || y >= m_Columns)
                throw std::out_of_range("Attempted to access an matrix element that is out of bounds");

            return m_ObjectElements[m_Columns * x + y];
    }
};
} // end Templates namespace
#endif // MATRIX_H
