# CPP03 — Inheritance

> 42 C++ Module 03
> Topic: inheritance, constructor/destructor chaining, and overriding member functions.

---

## General Evaluation Checklist

- [ ] Code compiles with `c++ -Wall -Wextra -Werror -std=c++98`
- [ ] No forbidden functions (`printf`, `malloc`, `free`, etc.)
- [ ] No `using namespace`
- [ ] No memory leaks
- [ ] Output ends with a newline

---

## ex00 — Aaaaand... OPEN!

**Main idea:** Implement a basic class in Orthodox Canonical Form.

**What to check:**
- `ClapTrap` class with OCF (default constructor, copy constructor, copy assignment, destructor).
- Private attributes: `name`, `hitPoints` (10), `energyPoints` (10), `attackDamage` (0).
- `attack(const std::string& target)`: costs 1 energy, prints damage message.
- `takeDamage(unsigned int amount)`: reduces hit points (not below 0).
- `beRepaired(unsigned int amount)`: costs 1 energy, restores hit points.
- All functions check that the ClapTrap has enough hit points and energy before acting.
- Constructors and destructor print informative messages.

**Key files:** `ClapTrap.{hpp,cpp}`, `main.cpp`

**Run:** `make && ./claptrap`

---

## ex01 — Serena, my love!

**Main idea:** Create a derived class that inherits from a base class.

**What to check:**
- `ScavTrap` inherits publicly from `ClapTrap`.
- `ClapTrap` attributes are changed from `private` to `protected` so derived classes can access them.
- `ScavTrap` constructors call the base `ClapTrap` constructor first, then set:
  - `hitPoints = 100`
  - `energyPoints = 50`
  - `attackDamage = 20`
- `ScavTrap` destructor calls its own message, then the base destructor.
- `ScavTrap::attack()` prints a different message from `ClapTrap::attack()`.
- `guardGate()` prints a gate-keeper mode message.
- Proper construction/destruction chaining is visible in the output.

**Key files:** `ClapTrap.{hpp,cpp}`, `ScavTrap.{hpp,cpp}`, `main.cpp`

**Run:** `make && ./scavtrap`

---

## ex02 — Repetitive work

**Main idea:** Add another derived class alongside the first one.

**What to check:**
- `FragTrap` inherits publicly from `ClapTrap`.
- `FragTrap` constructors call the base `ClapTrap` constructor first, then set:
  - `hitPoints = 100`
  - `energyPoints = 100`
  - `attackDamage = 30`
- `FragTrap` destructor calls its own message, then the base destructor.
- `highFivesGuys()` prints a positive high-fives request.
- `main.cpp` tests `ClapTrap`, `ScavTrap`, and `FragTrap` together.
- Copy constructor and assignment operator work correctly for all three classes.

**Key files:** `ClapTrap.{hpp,cpp}`, `ScavTrap.{hpp,cpp}`, `FragTrap.{hpp,cpp}`, `main.cpp`

**Run:** `make && ./fragtrap`

---

## Useful Evaluation Commands

```bash
# Compile
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o test

# Run each exercise
cd ex00 && make && ./claptrap
cd ex01 && make && ./scavtrap
cd ex02 && make && ./fragtrap
```
