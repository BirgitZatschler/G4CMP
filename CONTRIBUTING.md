# Contributing to the G4CMP Package

Last updated 4 August 2024, Michael Kelsey


The "Geant4 Condensed Matter Physics" (G4CMP) package is open source (see
[LICENSE](LICENSE)), but we are limiting code contributions to registered
developers from particle physics or related experimental collaborations.  If
you'd like to contribute, please send an e-mail to the package owner,
currently Michael Kelsey (Texas A&M) <kelsey AT slac.stanford.edu>, to be
added to the Contributors list for G4CMP.


## Reporting Problems

Until recently, G4CMP has been used primarily (and almost exclusively) by the
SuperCDMS Collaboration, members of which originally developed G4CMP.  As a
result, we have been using an internal issue tracking system in JIRA for
problems, requests, and development work.  We have made this tracking system
public on the [SLAC JIRA server](https://jira.slac.stanford.edu/browse/G4CMP);
G4CMP users may apply for a Crowd Account for access.


## Contribution Workflow

We are using a simplified version of the ["Git Flow"
workflow](https://nvie.com/posts/a-successful-git-branching-model/).  There
is a single line of development, on the **develop** branch, and a single
line of tagged "releases" (see below) on the **master** branch.  We are not
currently planning to rename the latter, to avoid disrupting existing clones
of the repository out in the world.


## External Forks

We would prefer that external forks not be used for submitting software
changes.  If you have created a fork, please create a JIRA ticket and a
feature branch within the repository, as discussed below.  We can merge the
resulting feature branch following our normal workflow.


## New Features

Contributors should make a named feature branch in this repository (rather
than a fork), branching from the HEAD of **develop** branch:
```
  git checkout develop
  git pull
  git checkout -b <branch-name>
```

Contributors should push their code changes directly back to the repository.
```
  [ edit, edit, edit ]
  git commit -m "Explanatory message" ...
  git push -u
```

When a feature branch is ready for merging, the contributor should add a
dated line to the top of the [ChangeHistory](ChangeHistory) file, with the
branch name and a brief explanation of its purpose.  The contributor should
then submit a Pull Request on GitHub, or send e-mail directly to the package
owner (above), requesting that it be merged onto **develop** branch.


## Merging Onto Develop

When a feature branch is merged onto **develop** branch, the package owner
will tag the merge commit with the name of the feature branch, and (first)
delete the feature branch from the repository.
```
  git checkout <branch-name>
  git pull
  git checkout develop
  git pull
  git merge --no-ff -m "Explanatory message" <branch-name>
  [ resolve conflicts, git merge --continue, etc. ]
  git branch -d <branch-name>
  git push origin :<branch-name>
  git tag -a -m "Explanatory message" <branch-name>
  git push ; git push --tag
```


## Pseudo-Release Tags

We have not been using GitHub's "Release" capability.  Instead, we have only
been merging the **develop** branch onto **master**, and applying a
[semantic verioning](https://semver.org) tag there, of the form
**g4cmp-Vxx-yy-zz**.  This is done exactly as with Merging onto Develop
(above), but without deleting the **develop** branch.

Before merging, the [ChangeHistory](ChangeHistory) file should be updated
with the new release tag and a brief explanation.  The individual feature
branches include will then be listed chronoligally below that line.
