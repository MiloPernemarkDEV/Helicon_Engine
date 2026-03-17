# Naming Conventions

To maintain readability and consistency across Helicon, follow these rules when contributing code.

---

## Classes & Structs
- `ClassName` — PascalCase for classes and structs  
- Example:

```cpp
class Renderer {
public:
    void renderFrame();
};

struct PhysicsSystem {
    void update();
};

## Functions & Methods
- `functionName` — camelCase for member and free functions  
- Example:

```cpp
void updateFrame();
int calculateScore(int base, int bonus);

## Member Variables
- `m_memberVariable` — prefix with `m_`  
- Example:

```cpp
class Player {
    int m_health;
    float m_speed;
};

## Local Variables
- `localVariable` — plain camelCase for function-local variables  
- Example:

```cpp
void movePlayer() {
    float deltaTime = 0.016f;
    int loopIndex = 0;
}

## Static Variables
- `s_staticVariable` — prefix with `s_`  
- Example:

```cpp
class GameManager {
    static int s_instanceCount;
};

## Macros & Constants
- `MACRO_NAME` — all uppercase  
- Example:

```cpp
#define MAX_BUFFER_SIZE 1024

## Enum Values
- Use **PascalCase** for enum names and their values  
- Example:

```cpp
enum class RenderMode {
    Wireframe,
    Solid,
    Textured
};

## Namespaces
- `NamespaceName` — PascalCase  
- Example:

```cpp
namespace Helicon {
    class Renderer {
    public:
        void renderFrame();
    };
}

## File Names
- Match the main class: `ClassName.h` / `ClassName.cpp`  
- Example: `Renderer.h` / `Renderer.cpp`

---

**Note:** Following these conventions helps keep the codebase consistent, readable, and maintainable for all contributors.
