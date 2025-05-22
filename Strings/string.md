✅ Definition

    A string is a sequence of characters.

    C++ supports:

        C-style strings (char arrays)

        C++ string class (std::string from the <string> library)

1️⃣ C-Style Strings (Character Arrays)
🔧 Declaration

char name[10] = "John";

⚠️ Important

    Must end with null character '\0'.

    Stored as an array of characters.

🧰 Functions (from <cstring>)

    strlen(str) – Get string length

    strcpy(dest, src) – Copy string

    strcmp(str1, str2) – Compare strings

    strcat(dest, src) – Concatenate

2️⃣ C++ Strings (std::string)

🧠 Header Required

#include <string>

🔧 Declaration

std::string name = "Alice";

✅ Features

    More powerful and flexible than C-style strings.

    Supports many operations directly.

🧰 Common Operations

name.length(); // Get length
name.empty(); // Check if empty
name.append(" Smith"); // Append
name.substr(0, 5); // Substring
name.find("li"); // Find position
name.replace(0, 5, "Bob");// Replace part

🔁 Input/Output

std::string name;
std::cin >> name; // Reads a word

std::getline(std::cin, name); // Reads a full line

🆚 C-Style vs std::string

Feature | C-Style (char[]) | std::string
Ease of Use | ❌ Manual handling | ✅ Built-in methods
Memory Safety | ❌ Prone to errors | ✅ Safer
Flexibility | ❌ Fixed operations | ✅ Dynamic features
