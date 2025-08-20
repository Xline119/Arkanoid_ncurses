#include <type_traits>
#include "GameField.hpp"
#include "Platform.hpp"

class Ball {
public:
    enum class Direction {
        leftUp,
        rightUp,
        leftDown,
        rightDown,
        stop
    };
    Ball(const Platform& platform);
    void move(const GameField& field, const Platform& platform);
    void setDirection(const GameField& field, const Platform& platform);
    void render(const GameField& field) const;
private:
// Collision detection block
    enum class Collision {
        none   = 0,
        left   = 1 << 0,
        right  = 1 << 1,
        top    = 1 << 2,
        bottom = 1 << 3
    };
    // Overloaded operators for Collision
    friend Collision operator|(Collision lhs, Collision rhs);
    friend Collision operator&(Collision lhs, Collision rhs);
    friend Collision operator|=(Collision& lhs, Collision rhs);
    friend Collision operator&=(Collision& lhs, Collision rhs);

    struct DirectionInfo {
        int y, x;
        Collision vert, horiz;
    };

    static constexpr DirectionInfo dirs[] {
        {-1, -1, Collision::top,    Collision::left},  // leftUp
        {-1,  1, Collision::top,    Collision::right}, // rightUp
        { 1, -1, Collision::bottom, Collision::left},  // leftDown
        { 1,  1, Collision::bottom, Collision::right}  // rightDown
    };
    
    void checkCollision(const GameField& field, const Platform& platform);
    template <typename ... Args>
    static bool hasCollision(Collision mask, Args ... args);
private:
    int posY_;
    int posX_;
    bool isMoving_;
    Direction movement_;
    Collision collisionMask_;
};

constexpr Ball::Collision operator|(Ball::Collision lhs, Ball::Collision rhs) {
    using U = std::underlying_type_t<Ball::Collision>;
    return static_cast<Ball::Collision>(static_cast<U>(lhs) | static_cast<U>(rhs));
}

constexpr Ball::Collision operator&(Ball::Collision lhs, Ball::Collision rhs) {
    using U = std::underlying_type_t<Ball::Collision>;
    return static_cast<Ball::Collision>(static_cast<U>(lhs) & static_cast<U>(rhs));
}

inline Ball::Collision operator|=(Ball::Collision& lhs, Ball::Collision rhs) {
    lhs = lhs | rhs;
    return lhs;
}

inline Ball::Collision operator&=(Ball::Collision& lhs, Ball::Collision rhs) {
    lhs = lhs & rhs;
    return lhs;
}