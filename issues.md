# CPP03 — Issues Found

## Issue 1 — CRITICAL: FragTrap doesn't override `attack()`

**Exercise:** ex02
**File:** `ex02/FragTrap.{hpp,cpp}`

**Problem:** FragTrap does not override `attack()`. It inherits ClapTrap's version,
which prints `"ClapTrap Fraggy attacks..."` instead of `"FragTrap Fraggy attacks..."`.

**Subject says:**
> "Now, implement a FragTrap class that inherits from ClapTrap. **It is very similar
> to ScavTrap.** However, its construction and destruction messages must be different."

ScavTrap overrides `attack()`. Since FragTrap is "very similar to ScavTrap", it
should also override `attack()` with a FragTrap-prefixed message.

**Current output:**
```
ClapTrap Fraggy attacks Bad Guy, causing 30 points of damage!
```

**Expected output:**
```
FragTrap Fraggy attacks Bad Guy, causing 30 points of damage!
```

**Fix:** Add `void attack(const std::string& target);` to `FragTrap.hpp` and
implement it in `FragTrap.cpp` following the same pattern as `ScavTrap::attack()`.

---

## Issue 2 — MODERATE: ScavTrap's `takeDamage()` and `beRepaired()` print "ClapTrap" prefix

**Exercise:** ex01
**File:** `ex01/ScavTrap.cpp` (missing overrides)

**Problem:** `takeDamage()` and `beRepaired()` are inherited from ClapTrap without
being overridden. When called on a ScavTrap, they print `"ClapTrap Scavvy takes..."`
and `"ClapTrap Scavvy repairs..."` instead of using the ScavTrap class name.

**Subject says:**
> "ClapTraps are aware of their individuality."

While the subject only explicitly requires `attack()` to print differently, the
"individuality" concept and the fact that these messages appear in the output make
this inconsistent.

**Current output:**
```
ClapTrap Scavvy takes 30 points of damage! Remaining hit points: 70
ClapTrap Scavvy repairs itself for 20 hit points! Current hit points: 90
```

**Expected output:**
```
ScavTrap Scavvy takes 30 points of damage! Remaining hit points: 70
ScavTrap Scavvy repairs itself for 20 hit points! Current hit points: 90
```

**Fix:** Override `takeDamage()` and `beRepaired()` in ScavTrap to print
`"ScavTrap"` prefix instead of `"ClapTrap"`.

---

## Issue 3 — MODERATE: FragTrap's `takeDamage()` and `beRepaired()` print "ClapTrap" prefix

**Exercise:** ex02
**File:** `ex02/FragTrap.cpp` (missing overrides)

**Problem:** Same as Issue 2 but for FragTrap. `takeDamage()` and `beRepaired()`
print `"ClapTrap Fraggy takes..."` and `"ClapTrap Fraggy repairs..."`.

**Current output:**
```
ClapTrap Fraggy takes 40 points of damage! Remaining hit points: 60
ClapTrap Fraggy repairs itself for 25 hit points! Current hit points: 85
```

**Expected output:**
```
FragTrap Fraggy takes 40 points of damage! Remaining hit points: 60
FragTrap Fraggy repairs itself for 25 hit points! Current hit points: 85
```

**Fix:** Override `takeDamage()` and `beRepaired()` in FragTrap to print
`"FragTrap"` prefix instead of `"ClapTrap"`.

---

## Issue 4 — MINOR: Comments in Spanish

**Exercise:** ex01, ex02
**Files:** `ex01/main.cpp`, `ex02/main.cpp`

**Problem:** Some comments are in Spanish:
- `ex01/main.cpp:18` — `//revisar como bota se trasnforma en botB`
- `ex01/main.cpp:22` — `//lo mismo`
- `ex02/main.cpp:17` — `//mirar asi aqui esta bien que claptrap scav tome el daño`

**Fix:** Translate comments to English or remove them.

---

## Issue 5 — MINOR: ex00 uses `private` attributes, ex01/ex02 use `protected`

**Exercise:** ex00 vs ex01/ex02

**Problem:** In `ex00/ClapTrap.hpp`, attributes are `private`. In `ex01/ClapTrap.hpp`
and `ex02/ClapTrap.hpp`, they are changed to `protected`.

The subject says for ex01: "ScavTrap will use the attributes of ClapTrap
(update ClapTrap accordingly)".

Changing `private` to `protected` is the correct way to allow derived classes to
access the attributes. However, the three exercises now have **different versions
of `ClapTrap.hpp` and `ClapTrap.cpp`**. If a student submits ex01, the evaluator
might check if ex00's ClapTrap still works with the `protected` change.

**Impact:** None functionally — `protected` is strictly more permissive than
`private`, and no external code accesses these members directly. But be aware
that each exercise's ClapTrap files differ.

---

## Summary

| # | Severity | Exercise | Issue |
|---|----------|----------|-------|
| 1 | **CRITICAL** | ex02 | FragTrap doesn't override `attack()` — prints "ClapTrap" prefix |
| 2 | **MODERATE** | ex01 | ScavTrap's `takeDamage`/`beRepaired` print "ClapTrap" prefix |
| 3 | **MODERATE** | ex02 | FragTrap's `takeDamage`/`beRepaired` print "ClapTrap" prefix |
| 4 | MINOR | ex01/ex02 | Comments in Spanish |
| 5 | MINOR | ex00→ex01 | Attributes changed from `private` to `protected` across exercises |
