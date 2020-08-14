# Godot Module Template with Unit Testing

This repository is meant to be used as a template for developing modules for the [Godot][1] engine in C++. It includes code to allow the developer to use [doctest][2] to write and run units tests on the module's code.

This is very much Work in Progress, see [Known Issues and Bugs section](#known-issues-and-bugs) section below. Therefore, here are a few things to keep in mind:

* I work mostly on Linux; that is to say, this code is not (yet) tested on Windows or OSX.
* The directory structure reflects my personal preferences. It should be easy to change to fit your personal needs with minimal modifications to the scons conscript file `SCsub`.
* I used the example code from the section on creating a [custom C++ module from the Godot documentation][6]. This should help new users to understand how this template works.
* I assume you're familiar with working on the command line, git, and building Godot.

## Installing and Usage

You should know how to download and build the [Godot source code][3]. If not, please follow the [instructions in the Godot documentation][4].

While there are several ways to use this template, currently the most convenient way is to use in as a git submodule in your Godot source tree.

### Add this Template as Submodule

Assuming you're in the directory with your Godot git repository, open your terminal and execute these commands:

```bash
[you@yourcomputer code]$ cd godot/modules
[you@yourcomputer modules]$ git submodule add https://github.com/georgjz/godot-module-template-with-unit-testing.git
[you@yourcomputer modules]$ mv godot-module-template-with-unit-testing mymodulename

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

```

## Planned Features

## Known Issues and Bugs
