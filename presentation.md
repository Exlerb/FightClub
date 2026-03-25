# Fight Club – Code Presentation Script

> **30-minute code review guide. Follow this order top-to-bottom.**
> Each section has a short "say this" note + the code to show.

---

## 1. Quick Overview (2 min)

**Say:**
> "The program is a turn-based console fight game written in plain C++.
> Two players each pick or build a character, then take turns using abilities
> until one character hits 0 HP. After the fight you can look at the all-time
> win/loss table, or play again immediately."

**Requirements covered:**
- ✅ At least 2 pre-made characters (we have 4)
- ✅ Each character has exactly 2 abilities
- ✅ More than 2 abilities to choose from (we have 8)
- ✅ Turn-based combat until one side is defeated
- ✅ Repeat fights with new characters
- ✅ Win/loss statistics for every character

---

## 2. Data Structures (5 min)

### `Ability` struct
```cpp
struct Ability {
    std::string name;
    int         damage;
    int         heal;
    std::string description;
};
```

**Say:**
> "An ability is just four fields: a name, how much damage it deals to the
> opponent, how much HP it restores to the user, and a description string
> shown in the menu. Simple value type – no inheritance needed."

### `ABILITY_POOL`
```cpp
const std::vector<Ability> ABILITY_POOL = {
    { "Fireball",     40,  0,  "Hurls a ball of fire  — 40 dmg" },
    { "Heal",          0, 30,  "Recovers health       — +30 HP" },
    { "Shield Bash",  20, 10,  "Bash + minor heal     — 20 dmg / +10 HP" },
    // …8 total
};
```

**Say:**
> "All available abilities live in one global constant vector.
> Pre-made characters reference entries by index.
> Custom characters let the player pick any two indices from this list."

---

## 3. The `Character` Class (5 min)

```cpp
class Character {
public:
    std::string name;
    int         maxHP, hp;
    Ability     ability1, ability2;

    Character(const std::string& n, int hp, Ability a1, Ability a2);

    bool isAlive() const { return hp > 0; }
    void resetHP()       { hp = maxHP; }
    void useAbility(int choice, Character& target);
};
```

**Say:**
> "Character stores everything needed for one fighter.
> `maxHP` lets us restore health between fights with `resetHP()`.
> `isAlive()` is the single exit condition for the battle loop."

### `useAbility` – the core game mechanic

```cpp
void useAbility(int choice, Character& target) {
    Ability& ab = (choice == 1) ? ability1 : ability2;

    if (ab.damage > 0) {
        target.hp = std::max(0, target.hp - ab.damage);
        // print damage report
    }
    if (ab.heal > 0) {
        hp = std::min(maxHP, hp + ab.heal);
        // print heal report
    }
}
```

**Say:**
> "One method handles both attack and heal because an ability can do both
> (e.g. Shield Bash). `std::max/min` clamps HP so it never goes below 0
> or above `maxHP`. That's the entire combat formula."

---

## 4. Statistics (3 min)

```cpp
std::map<std::string, std::pair<int,int>> g_stats;
//                                         wins  losses

void recordResult(const std::string& winner, const std::string& loser) {
    g_stats[winner].first++;
    g_stats[loser].second++;
}
```

**Say:**
> "Stats are stored in a global map keyed on character name.
> `std::map` default-constructs the value to `{0,0}` on first access,
> so we never need to initialise it explicitly.
> This persists across all fights within one program session."

---

## 5. Character Selection (5 min)

```cpp
Character selectCharacter(const std::string& label) {
    // mode 1 → pre-made, mode 2 → custom
}
```

### Pre-made path
```cpp
auto presets = presetCharacters();   // returns 4 hardcoded Characters
// show numbered list
int pick = readInt(1, (int)presets.size());
return presets[pick - 1];
```

### Custom path
```cpp
std::cin >> name;
printAbilityPool();            // numbered list of all 8 abilities
int a1 = readInt(1, 8);
int a2 = readInt(1, 8);
return { name, 100, ABILITY_POOL[a1-1], ABILITY_POOL[a2-1] };
```

**Say:**
> "Custom characters always start with 100 HP.
> `readInt(lo, hi)` is a small helper that loops until the user
> enters a valid integer — prevents crashes from bad input."

---

## 6. The Battle Loop (5 min)

```cpp
void battle(Character c1, Character c2) {
    c1.resetHP();  c2.resetHP();        // always start fresh

    Character* current  = &c1;
    Character* opponent = &c2;
    int round = 1;

    while (c1.isAlive() && c2.isAlive()) {
        // print round header + HP bars
        // active player picks ability 1 or 2
        current->useAbility(choice, *opponent);
        std::swap(current, opponent);   // alternate turns
        round++;
    }

    Character* winner = c1.isAlive() ? &c1 : &c2;
    Character* loser  = c1.isAlive() ? &c2 : &c1;
    recordResult(winner->name, loser->name);
}
```

**Say:**
> "Characters are passed **by value** so the originals are never mutated –
> stats in `g_stats` are what persist, not HP.
> Two raw pointers (`current` / `opponent`) swap each round to alternate
> turns without copying data. The loop ends the moment either HP hits 0."

---

## 7. Main Loop (2 min)

```cpp
while (true) {
    // print menu: 1. Battle  2. Stats  3. Quit
    if (choice == 1) {
        Character p1 = selectCharacter("Player 1");
        Character p2 = selectCharacter("Player 2");
        battle(p1, p2);
    } else if (choice == 2) {
        showStats();
    } else {
        break;
    }
}
```

**Say:**
> "The outer loop is the entire game. After any battle you land back here
> and can immediately start a new fight with different characters.
> Stats accumulate until the program exits."

---

## 8. Design Decisions & Trade-offs (3 min)

| Decision | Why |
|---|---|
| `struct Ability` (not class) | Pure data, no behaviour → struct is idiomatic |
| Characters passed by value to `battle()` | Keeps originals clean; HP resets are local |
| Global `g_stats` map | Simplest persistent store for a single-session CLI game |
| No inheritance / polymorphism | Requirements don't need it; KISS principle |
| `readInt()` helper | Single place to handle bad input; no repeated while-loops |
| 8 abilities, 4 presets | Exceeds the "≥2 presets, >2 abilities" requirement comfortably |

---

## 9. Possible Extensions (1 min, if time allows)

- Add a `speed` stat to determine who attacks first
- Persistent stats saved to a file (`std::fstream`)
- Random AI opponent (CPU picks an ability randomly)
- Items / consumables usable during battle

---

*End of presentation — total ~30 minutes*
