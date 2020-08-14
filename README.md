# Godot Module Template with Unit Testing

This repository is meant to be used as a template for developing modules for the [Godot][1] engine in C++. It includes code to allow the developer to use [doctest][2] to write and run units tests on the module's code.

This is very much Work in Progress, see [Known Issues and Bugs section](#known-issues-and-bugs) section below. Therefore, here are a few things to keep in mind:

* I work mostly on Linux; that is to say, this code is not (yet) tested on Windows or OSX.
* The directory structure reflects my personal preferences. It should be easy to change to fit your personal needs with minimal modifications to the scons conscript file `SCsub`.
* I used the example code from the section on creating a [custom C++ module from the Godot documentation][6]. This should help new users to understand how this template works.
* I assume you're familiar with working on the command line, git, and building Godot.
* This is a very early stage, I haven't worked with Scons before, so expect a lot of weird/unsual things in that regard.

## Installing and Usage

You should know how to download and build the [Godot source code][3]. If not, please follow the [instructions in the Godot documentation][4].

While there are several ways to use this template, currently the most convenient way is to use in as a git submodule in your Godot source tree.

### Add this Template as Submodule

Assuming you're in the directory with your Godot git repository, open your terminal and execute these commands:

```bash
[you@yourcomputer code]$ cd godot/modules
[you@yourcomputer modules]$ git submodule add https://github.com/georgjz/godot-module-template-with-unit-testing.git mymodulename
```

Keep in mind, that this submodule will have this Github repository as remote origin. You may want to remove it:

```bash
[you@yourcomputer modules]$ cd mymodulename
[you@yourcomputer mymodulename] git remote rm origin
```

This step is optional, but I like to keep my repositories clean. Once you start writing your own code for the module, you probably won't ever pull from this Github repository again.

Lastly, commit your submodule to your Godot repository:

```bash
[you@yourcomputer mymodulename] cd ../..
[you@yourcomputer godot] git add modules/mymodulename
[you@yourcomputer godot] git commit -m "update mymodulename submodule"
```

### Usage

Once you've added the submodule, checkout the master branch (or branch as fits your needs; remember, a submodule is just another git repository) and start writing code:

```bash
[you@yourcomputer mymodulename] git checkout master
```

Now edit and test your code as you see fit. Once you want to commit your new code to the submodule, do this:

```bash
[you@yourcomputer mymodulename] git commit -a -m "super cool new code!"
[you@yourcomputer mymodulename] cd ../..
[you@yourcomputer godot] git add modules/mymodulename
[you@yourcomputer godot] git commit -m "update mymodulename submodule"
```

### Running Unit Tests

This template uses [doctest][2] for creating unit tests (the Godot engine itself uses the same framework). Please read this [doctest tutorial][5] if you haven't used it before.

To build the test program, move to your module directory and run:

```bash
[you@yourcomputer mymodulename] scons -u
```

This will create an executable called `runTests.<depends.on.your.settings>`. Run this executable so see the test results, here's an example using the code in this repository:

```bash
[you@yourcomputer mymodulename] ./runTests.x.y.z
[doctest] doctest version is "2.4.0"
[doctest] run with "--help" for options
===============================================================================
modules/summator/tests/summator_tests.cpp:7:
TEST CASE:  testing the Summator class

modules/summator/tests/summator_tests.cpp:7: FATAL ERROR: test case CRASHED: SIGSEGV - Segmentation violation signal

===============================================================================
[doctest] test cases:      1 |      0 passed |      1 failed |      0 skipped
[doctest] assertions:      0 |      0 passed |      0 failed |
[doctest] Status: FAILURE!
Segmentation fault (core dumped)
```

This crush was expected; see [Godot Related Issues](#godot-related-issues) below.

## Planned Features

Here's a few things I'd like to add in the future:

* Allow the module to be built external; i.e., remove the need for the code to be placed in `godot/modules`, instead, use `scons custom_modules="path/to/your/module".
* Improve unit testing by allowing tests to be written in several files.
* A more detailed tutorial how to write unit tests.
* Improved build time and size (see issues below).

## Known Issues and Bugs

This is a list of known issues and bugs:

* Currently, the build time and size is not optimized. The resulting `runTests.x.y.z` will be almost the size of Godot itself (~350MB on my Linux system, so YMMV). I want to improve the `SCsub` code to make sure the test program only includes the object files the tests actually need.
* The test program is rebuilt every time some module code changes. It would be nice to let the user control whether to rebuild the test programs or not.

## Godot Related Issues

* The test program in this repository crashed with a Segmentation fault (see example above); after some quick and dirty gdb inspection, I think the issue here is that the `Summator` class inherits from Godot's `Reference` class. Godot takes care of pointer clean up for that class, so using `delete cut;` like it is done in `tests/summator_tests.cpp`, is wrong. Comment out that line, and the tests will run successfully.

## Contributing

As I said, this is the first time working with Scons, so if you have more experience with it, please consider submitting a pull request to improve this template!

[1]: https://godotengine.org
[2]: https://github.com/onqtam/doctest
[3]: https://github.com/godotengine
[4]: https://docs.godotengine.org/en/stable/development/compiling/index.html
[5]: https://github.com/onqtam/doctest/blob/master/doc/markdown/tutorial.md
[6]: https://docs.godotengine.org/en/stable/development/cpp/custom_modules_in_cpp.html
