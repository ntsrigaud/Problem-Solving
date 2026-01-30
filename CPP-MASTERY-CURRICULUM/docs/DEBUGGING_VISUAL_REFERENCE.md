# VS Code C++ Debugging - Visual Reference

## Configuration Files Structure

```
CPP-MASTERY-CURRICULUM/
├── .vscode/
│   ├── launch.json         ← Debugger configuration
│   ├── tasks.json          ← Build configuration
│   └── c_cpp_properties.json
├── debug_test.cpp          ← Test program for debugging
├── area_calculator.cpp     ← Your assignment (now fixed!)
├── temperature_converter.cpp
├── DEBUGGING_QUICKSTART.md ← Start here!
└── docs/DEBUGGING_GUIDE.md  ← Complete reference
```

---

## The Debugging Lifecycle

```
┌─────────────────────────────────────────────────┐
│ 1. Write C++ Code                               │
│    └─ program.cpp                               │
└─────────────────┬───────────────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────────────┐
│ 2. Compile with Debug Symbols                   │
│    └─ clang++ -g -O0 program.cpp -o program     │
│    └─ Happens automatically when you press F5   │
└─────────────────┬───────────────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────────────┐
│ 3. Set Breakpoints                              │
│    └─ Click in gutter (left of line numbers)    │
│    └─ Red dots appear                           │
└─────────────────┬───────────────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────────────┐
│ 4. Start Debugger (F5)                          │
│    └─ VS Code launches LLDB                     │
│    └─ Program starts running                    │
└─────────────────┬───────────────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────────────┐
│ 5. Debugger Pauses at Breakpoint                │
│    └─ Yellow arrow shows current line           │
│    └─ Variables panel shows values              │
└─────────────────┬───────────────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────────────┐
│ 6. Inspect and Step Through Code                │
│    ├─ F10: Step Over (next line)                │
│    ├─ F11: Step Into (enter function)           │
│    ├─ Shift+F11: Step Out (exit function)       │
│    └─ Hover over variables to see values        │
└─────────────────┬───────────────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────────────┐
│ 7. Continue or Stop                             │
│    ├─ F5: Continue to next breakpoint           │
│    └─ Shift+F5: Stop debugging                  │
└─────────────────────────────────────────────────┘
```

---

## VS Code Debug UI Layout

```
┌──────────────────────────────────────────────────────────────┐
│ Menu Bar                                                     │
├──────────────────────────────────────────────────────────────┤
│ ┏━━━━━━━━━━━━━━━┓  Debug Toolbar (appears when debugging)    │
│ ┃ ▶️ Continue   ┃  F5                                        │
│ ┃ ⤵️ Step Over  ┃  F10  ← Most used                          │
│ ┃ ⬇️ Step Into  ┃  F11                                       │
│ ┃ ⤴️ Step Out   ┃  Shift+F11                                 │
│ ┃ 🔄 Restart    ┃  Ctrl+Shift+F5                             │
│ ┃ ⏹️ Stop       ┃  Shift+F5                                  │
│ ┗━━━━━━━━━━━━━━━┛                                            │
├───────────────┬──────────────────────────────────────────────┤
│               │                                              │
│  EXPLORER     │  Editor Area                                 │
│  ├─ Files     │  ┌────────────────────────────────────────┐  │
│  └─ Outline   │  │  1  #include <iostream>                │  │
│               │  │  2                                     │  │
│  RUN & DEBUG  │  │  3  int main() {                       │  │
│  ├─ Variables │  │  4 🔴 int x = 10;  ← Breakpoint        │  │
│  │  ├─ x: 10  │  │  5 ➡️ int y = 20;  ← Current line      │  │
│  │  └─ y: 20  │  │  6      int sum = x + y;               │  │
│  ├─ Watch     │  │  7      return 0;                      │  │
│  │  └─ x + y  │  │  8  }                                  │  │
│  ├─ Call Stack│  └────────────────────────────────────────┘  │
│  │  └─ main() │                                              │
│  └─ Breakpnts │  Debug Console (below)                       │
│     └─ file:4 │  > x                                         │
│               │  10                                          │
│               │  > y                                         │
│               │  20                                          │
│               │  > x + y                                     │
│               │  30                                          │
└───────────────┴──────────────────────────────────────────────┘
```

---

## Breakpoint States

```
🔴 Active Breakpoint
   └─ Will pause execution here
   └─ Click gutter to toggle

⚪ Disabled Breakpoint
   └─ Won't pause (right-click → Disable)
   └─ Keep for later use

◯  Hollow/Gray Breakpoint
   └─ Warning: No debug symbols!
   └─ Recompile with -g flag

💎 Conditional Breakpoint
   └─ Only breaks when condition true
   └─ Right-click → Edit Breakpoint

📍 Logpoint
   └─ Prints message without stopping
   └─ Right-click gutter → Add Logpoint
```

---

## Stepping Visualization

```cpp
int factorial(int n) {          // ← F11 enters here
    if (n <= 1) {               // ← F10 moves here
        return 1;               // ← F10 moves here
    }                           //
    return n * factorial(n-1);  // ← F11 enters recursion
}                               // ← Shift+F11 exits function

int main() {
    int x = 5;                  // ← Start here (F10)
    int result = factorial(x);  // ← F10 skips function
                                //   F11 enters function
    return 0;                   // ← Arrives here after function
}
```

**F10 (Step Over):**

```
x = 5;              ← Execute this
result = factorial(x);  ← Execute whole function, don't go inside
return 0;           ← Next stop
```

**F11 (Step Into):**

```
x = 5;              ← Execute this
result = factorial(x);  ← Jump INTO factorial
  ↓
int factorial(int n) {  ← Now inside function
```

---

## Variable Inspection

### Three Ways to See Variable Values

#### 1. Hover (Easiest)

```cpp
int x = 10;
int y = 20;  ← Hover mouse over 'x' or 'y'
             Shows: x: 10
```

#### 2. Variables Panel (Automatic)

```
VARIABLES
  Local
    ├─ x: 10
    ├─ y: 20
    └─ sum: 30
```

#### 3. Debug Console (Interactive)

```
> x
10
> y
20
> x + y
30
> x * 2
20
```

---

## Call Stack Example

```cpp
void helper(int n) {
    int local = n * 2;    // ← Breakpoint here
}

void process(int x) {
    helper(x + 1);
}

int main() {
    process(5);
}
```

**Call Stack shows:**

```
Call Stack
  ├─ helper (int n=6)         ← Currently here
  │  └─ local: 12
  ├─ process (int x=5)        ← Click to see process's variables
  └─ main ()                  ← Click to see main's variables
```

**Click any frame to see its variables and code location.**

---

## Common Debugging Patterns

### Pattern 1: Finding a Bug in Calculation

```cpp
double average = total / count;  // Wrong!

// Debug:
// 1. Set breakpoint on this line
// 2. Check: total = 100, count = 3
// 3. Step over (F10)
// 4. Check: average = 33 (not 33.333...)
// 5. Aha! Integer division!
// Fix: double average = static_cast<double>(total) / count;
```

### Pattern 2: Following Logic Flow

```cpp
if (x > 10) {
    // Branch A
} else {
    // Branch B  ← Did we take the right branch?
}

// Debug:
// 1. Set breakpoint before if
// 2. Check x value
// 3. Step over (F10)
// 4. Verify which branch executed
```

### Pattern 3: Investigating a Crash

```cpp
int* ptr = nullptr;
*ptr = 42;  // Crash here!

// Debug:
// 1. Run without breakpoints (will crash)
// 2. Debugger auto-stops at crash
// 3. Check Variables: ptr = 0x0 (null)
// 4. Check Call Stack: how did we get here?
// 5. Fix: check ptr != nullptr before using
```

### Pattern 4: Loop Investigation

```cpp
for (int i = 0; i < 10; ++i) {
    process(i);  // Problem happens at i=5
}

// Debug:
// 1. Set conditional breakpoint: i == 5
// 2. Debugger pauses only when i=5
// 3. Step into process() to investigate
```

---

## Compilation Flags Impact

### With -g (Debug Symbols)

```bash
clang++ -g program.cpp -o program
```

✅ Breakpoints work  
✅ Variable names visible  
✅ Line numbers accurate  
✅ Can step through code  
⚠️ Larger executable (~10x size)

### With -g -O0 (No Optimization)

```bash
clang++ -g -O0 program.cpp -o program
```

✅ All of the above  
✅ Variables not optimized away  
✅ Code matches source exactly  
✅ Best debugging experience  
⚠️ Slower execution

### With -O2 (Optimized)

```bash
clang++ -g -O2 program.cpp -o program
```

⚠️ Code reordered  
⚠️ Variables show `<optimized out>`  
⚠️ Lines may execute in unexpected order  
❌ Poor debugging experience  
✅ Fast execution

**Rule:** Always use `-O0` when debugging!

---

## Keyboard Shortcuts Summary

### Essential

| Key | Action            |
| --- | ----------------- |
| F5  | Start/Continue    |
| F9  | Toggle Breakpoint |
| F10 | Step Over         |
| F11 | Step Into         |

### Advanced

| Key           | Action     |
| ------------- | ---------- |
| Shift+F5      | Stop       |
| Ctrl+Shift+F5 | Restart    |
| Shift+F11     | Step Out   |
| Cmd+K Cmd+I   | Show Hover |

---

## Configuration Quick Reference

### launch.json (Minimal)

```json
{
  "type": "lldb",
  "request": "launch",
  "program": "${fileDirname}/${fileBasenameNoExtension}",
  "preLaunchTask": "build-task-label"
}
```

### tasks.json (Minimal)

```json
{
  "label": "build-task-label",
  "command": "clang++",
  "args": ["-g", "-O0", "${file}", "-o", "${fileBasenameNoExtension}"]
}
```

---

## Troubleshooting Flowchart

```
Debugging not working?
    |
    ├─ Breakpoints gray/hollow?
    │   └─ Missing -g flag
    │       └─ Fix: Add -g to tasks.json, rebuild
    |
    ├─ Variables show <optimized out>?
    │   └─ Optimization enabled
    │       └─ Fix: Add -O0 to tasks.json, rebuild
    |
    ├─ Debugger won't launch?
    │   └─ Check extensions installed
    │       └─ Fix: Install ms-vscode.cpptools or vadimcn.vscode-lldb
    |
    ├─ Wrong file being debugged?
    │   └─ Check program path in launch.json
    │       └─ Fix: Use ${fileDirname}/${fileBasenameNoExtension}
    |
    └─ Still not working?
        └─ Test manually:
            └─ clang++ -g -O0 test.cpp -o test && lldb test
```

---

## Success Checklist

Before starting to debug, verify:

- [x] VS Code C++ extension installed
- [x] Compiler includes `-g` flag
- [x] Compiler includes `-O0` flag
- [x] launch.json has correct `program` path
- [x] tasks.json label matches launch.json preLaunchTask
- [x] Breakpoint appears as solid red dot
- [x] Program compiles without errors

**All checked?** Press F5 and start debugging! 🚀

---

## Learning Path

**Week 1-2:** Basic stepping and variable inspection  
**Week 3:** Function call stack and parameters  
**Week 4:** Array and loop debugging  
**Week 5:** Pointer inspection and memory  
**Week 6:** Object state and lifecycle  
**Week 7-8:** Container contents and iterators

Start simple, build up complexity! 🎯
