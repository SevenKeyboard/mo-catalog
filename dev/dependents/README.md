# Dependents

Raw `dumpbin /dependents` outputs for MoCatalog and Boost.Locale binaries.

Developer Command Prompt for Visual Studio:
- Tools -> Command Line -> Developer Command Prompt

```bat
dumpbin /dependents <dll>
```

Visual C++ Redistributable:

* Use the latest supported v14 Redistributable for the target architecture. ([Microsoft Learn](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170))
* x86: `https://aka.ms/vc14/vc_redist.x86.exe` ([Microsoft Learn](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170))
* x64: `https://aka.ms/vc14/vc_redist.x64.exe` ([Microsoft Learn](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170))

Redistributable command-line example:

```bat
vc_redist.x64.exe /install /passive /norestart
```

* `/passive` shows progress without requiring user interaction.
* `/quiet` runs without a UI.
* `/norestart` suppresses restart attempts. ([Microsoft Learn](https://learn.microsoft.com/en-us/cpp/windows/redistributing-visual-cpp-files?view=msvc-170))