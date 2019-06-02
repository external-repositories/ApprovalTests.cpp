<a id="top"></a>

# Contributing to ApprovalTests.cpp



<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Contents**

- [Contributing - pairing and pull requests](#contributing---pairing-and-pull-requests)
- [Documentation](#documentation)
  - [Creating new pages](#creating-new-pages)
  - [Internal links need to be absolute](#internal-links-need-to-be-absolute)
  - [Adding code and file samples](#adding-code-and-file-samples)
  - [Checking the documentation](#checking-the-documentation)
- [Releases](#releases)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->


## Contributing - pairing and pull requests

The default way to add to most repositories is to fork and then create a pull-request.

This is **NOT** the default way to contribute to Approval Tests!

If you have something that you would like Approval Tests to have, including a bug you would like removed, we suggest you set up a pairing session (usually Skype or Facetime) with either [Llewellyn](mailto:llewellyn.falco@gmail.com) or [Clare](mailto:github@cfmacrae.fastmail.co.uk) or both.

A typical session lasts between 60 to 90 minutes. We do the work directly on master, on our own machines, with screen-sharing, and commit and push the results throughout the session. This results in quicker, higher-quality work. It gives us a better understanding of how people are using Approval Tests and the problems they encounter with it, and these sessions are also quite fun.

We use github's "co-author" feature, so everyone in the pairing session gets credit for the work. Virtually this entire project has been developed in this way, and is stronger for it.

## Documentation

We welcome improvements to the documentation! Here's how we manage the documentation files. 

### Creating new pages

*Note: All the master Markdown pages in this project are called `mdsource/[something].source.md`*

If creating a new Markdown page, please make a copy of [doc/mdsource/TemplatePage.source.md](/doc/mdsource/TemplatePage.source.md#top).
This contains some boilerplate text which is tedious to create by hand.

The new file needs to be in a `mdsource` sub-directory.

If the new page will be outside of the [doc](/doc/) folder, delete the following lines at the end:

```
---
   
[Back to User Guide](/doc/README.md#top)
```

### Internal links need to be absolute 

All references to other files in this project, such as hyperlinks and images, must specify the full path from the root of the repository. This will allow those links to work correctly in both the source and generated markdown files. Relative paths cannot work for both the source and the target file. 

For example, use this:

```markdown
* [this link will work everywhere](/doc/Reporters.md#top)
```

Not this:

```markdown
* [this link is wrong](doc/Reporters.md#top)
```

And not this:

```markdown
* [this link is wrong](Reporters.md#top)
```

### Adding code and file samples

We use Simon Cropp's [MarkdownSnippets](https://github.com/SimonCropp/MarkdownSnippets) tool to embed source code and other files in Markdown pages.

**How it works:**

* Call the source file `[something].source.md`.
* Make sure it is in a `mdsource` directory
* See the [MarkdownSnippets](https://github.com/SimonCropp/MarkdownSnippets) documentation for how to:
    * annotate snippets of source code, 
    * reference the snippets in documentation.
* Run  `run_markdown_templates.sh` **before commit**, every time a `.source.md` file is updated
    * See [run_markdown_templates.sh](/run_markdown_templates.sh).
    * This will update the tables of contents and the machine-generated `[something].md` files.
    * If this does not work, see that script for how to install the tools it uses

### Checking the documentation

The script [fix_markdown.sh](/fix_markdown.sh) can be used to do some checks of the Markdown documentation files.

It can be run in cygwin with:

```bash
cat ./fix_markdown.sh | dos2unix | bash
```

## Releases

* Everything for releases is in [the build directory](/build/)
* There's more information in [How To Release](/build/HowToRelease.md#top)

---

[Back to User Guide](/doc/README.md#top)