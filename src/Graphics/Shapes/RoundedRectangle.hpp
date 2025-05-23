#pragma once

#include <SFML/Graphics.hpp>

// TODO: Fill methods of this class
class RoundedRectangleShape final : public sf::Shape {
public:
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
    explicit RoundedRectangleShape(sf::Vector2f size = {}, float radius = 0.0f);

    ////////////////////////////////////////////////////////////
    /// \brief Set the size of the rectangle
    ///
    /// \param size New size of the rectangle
    ///
    /// \see `getSize`
    ///
    ////////////////////////////////////////////////////////////
    void setSize(sf::Vector2f size);

    ////////////////////////////////////////////////////////////
    /// \brief Get the size of the rectangle
    ///
    /// \return Size of the rectangle
    ///
    /// \see `setSize`
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] sf::Vector2f getSize() const;

    ////////////////////////////////////////////////////////////
    /// \brief Set the corner radius of the rectangle
    ///
    /// \param radius New radius % of the rectangle's angles
    ///
    /// \see `getCornerRadius`
    ///
    ////////////////////////////////////////////////////////////
    void setCornerRadius(float radius);

    ////////////////////////////////////////////////////////////
    /// \brief Gets the corner radius of the rectangle
    ///
    /// \return Radius % of the rectangle's angles
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] float getCornerRadius() const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the number of points defining the shape
    ///
    /// \return Number of points of the shape. For rectangle
    ///         shapes, this number is always 4.
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] std::size_t getPointCount() const override;

    ////////////////////////////////////////////////////////////
    /// \brief Get a point of the rectangle
    ///
    /// The returned point is in local coordinates, that is,
    /// the shape's transforms (position, rotation, scale) are
    /// not taken into account.
    /// The result is undefined if `index` is out of the valid range.
    ///
    /// \param index Index of the point to get, in range [0 .. 3]
    ///
    /// \return `index`-th point of the shape
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] sf::Vector2f getPoint(std::size_t index) const override;

    ////////////////////////////////////////////////////////////
    /// \brief Get the geometric center of the rectangle
    ///
    /// The returned point is in local coordinates, that is,
    /// the shape's transforms (position, rotation, scale) are
    /// not taken into account.
    ///
    /// \return The geometric center of the shape
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] sf::Vector2f getGeometricCenter() const override;

private:
    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    sf::Vector2f m_size;           //!< Size of the rectangle
    float m_percentRadius;         //!< Rounded corners % radius
    sf::CircleShape m_topLeft;     //!< Top left circle
    sf::CircleShape m_topRight;    //!< Top right circle
    sf::CircleShape m_bottomLeft;  //!< Bottom left circle
    sf::CircleShape m_bottomRight; //!< Bottom right circle
};