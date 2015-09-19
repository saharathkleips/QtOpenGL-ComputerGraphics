#ifndef VERTEX_H
#define VERTEX_H

#include <QVector3D>

class Vertex
{
public:
    //  CONSTRUCTORS
    Q_DECL_CONSTEXPR Vertex();
    Q_DECL_CONSTEXPR explicit Vertex(const QVector3D &position);
    Q_DECL_CONSTEXPR Vertex(const QVector3D &position, const QVector3D &color);

    //  GETTERS / SETTERS
    Q_DECL_CONSTEXPR const QVector3D& position() const;
    Q_DECL_CONSTEXPR const QVector3D& color() const;
    void setPosition(const QVector3D& position);
    void setColor(const QVector3D& color);

    //  OPENGL HELPERS
    static const int PositionTupleSize = 3;
    static const int ColorTupleSize = 3;
    static Q_DECL_CONSTEXPR int positionOffset();
    static Q_DECL_CONSTEXPR int colorOffset();
    static Q_DECL_CONSTEXPR int stride();

private:
    QVector3D m_position;
    QVector3D m_color;
};

Q_DECLARE_TYPEINFO(Vertex, Q_MOVABLE_TYPE);
#endif  //  VERTEX_H