---
layout:    en_post
Topic:     Utility Software
Title:     Git Commands
Revised:   2019-04-29 10:30:00 +08 @ China-Guangdong-ShenZhen +08
Authors:   BSS9395
Resources:
---

| *`git`*                   | `--help --version`                                           | The stupid content tracker.                                  |
| :------------------------ | :----------------------------------------------------------- | :----------------------------------------------------------- |
|                           |                                                              |                                                              |

### A a

| *`git add`*               | `--all --force --interactive --patch`                        | Add file contents to the index.                              |
| :------------------------ | :----------------------------------------------------------- | :----------------------------------------------------------- |
| *`git am`*                | `--3way --abort --interactive --resolved --skip`             | Apply a series of patches from a mailbox.                    |
| *`git apply`*             |                                                              | Apply a patch to files and/or to the index.                  |
| *`git archive`*           | `--format`                                                   | Create an archive of files from a named tree.                |

### B b

| *`git bisect`*            |                                                              | Use binary search to find the commit that introduced a bug.  |
| :------------------------ | :----------------------------------------------------------- | :----------------------------------------------------------- |
| *`git blame`*             |                                                              | Show what revision and author last modified each line of a file. |
| *`git branch`*            | `-v -vv` `--merged --no-merged --set-upstream-to --unset-upstream-to` | List, create, or delete branches.                            |
| *`git bundle`*            |                                                              | Move objects and refs by archive.                            |
| *`git bundle create`*     |                                                              |                                                              |
| *`git bundle list-heads`* |                                                              |                                                              |
| *`git bundle verify`*     |                                                              |                                                              |

### C c

| *`git cat-file`*      | `-p -s -t`                   | Provide content or type and size information for repository objects. |
| :-------------------- | :--------------------------- | :----------------------------------------------------------- |
| *`git checkout`*      | `-b` `--track`               | Switch branches or restore working tree files.               |
| *`git cherry-pick`*   |                              | Apply the changes introduced by some existing commits.       |
| *`git clean`*         | `-d -f -i -n -x`             | Remove untracked files from the working tree.                |
| *`git clone`*         | `-b -o` `--bare --recursive` | Clone a repository into a new directory.                     |
| *`git commit`*        | `-a -m -v -S` `--amend`      | Record changes to the repository.                            |
| *`git commit-tree`*   | `-p`                         | Create a new commit object.                                  |
| *`git config`*        | `-f` `--list`                | Get and set repository or global options.                    |
| *`git count-objects`* | `-v`                         | Count unpacked number of objects and their disk consumption. |

### D d

| *`git describe`*          |                                                              | Give an object a human readable name based on an available ref. |
| :------------------------ | :----------------------------------------------------------- | :----------------------------------------------------------- |
| *`git diff`*              | `-b -p` `--check --staged --submodule`                       | Show changes between commits, commit and working tree, etc.  |
| *`git difftool`*          | `--tool= --tool-help`                                        | Show changes using common diff tools.                        |

### F f

| *`git fast-import`*   |                                      | Backend for fast Git data importers.                         |
| :-------------------- | :----------------------------------- | :----------------------------------------------------------- |
| *`git fetch`*         | `--all`                              | Download objects and refs from another repository.           |
| *`git filter-branch`* | `--all --index-filter --tree-filter` | Rewrite branches.                                            |
| *`git format-patch`*  | `-M`                                 | Prepare patches for e-mail submission.                       |
| *`git fsck`*          | `--full`                             | Verifies the connectivity and validity of the objects in the database. |

### G g

| *`git gc`*   |                   | Cleanup unnecessary files and optimize the local repository. |
| :----------- | :---------------- | :----------------------------------------------------------- |
| *`git grep`* | `-n -p` `--count` | Print lines matching a pattern.                              |

### H h

| *`git help`*        |                | Display help information about Git.                          |
| :------------------ | :------------- | :----------------------------------------------------------- |
| *`git hash-object`* | `-w` `--stdin` | Compute object ID and optionally creates a blob from a fileCompute object ID and optionally creates a blob from a file. |

### I i

| *`git init`*      | `--bare --shared` | Create an empty Git repository or reinitialize an existing one. |
| :---------------- | :---------------- | :----------------------------------------------------------- |
| *`git imap-send`* |                   | Send a collection of patches from stdin to an IMAP folder.   |

### L l

| *`git log`*       | `-g -p -S` `-- --all --all-match --author --graph --decorate --format --grep --left-right --merges --no-merges --not --show-signature --since --stat --pretty=format: --until` | Show commit logs.                                            |
| :---------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| *`git ls-files`*  |                                                              | Show information about files in the index and the working tree. |
| *`git ls-remote`* |                                                              | List references in a remote repository                       |
| *`git ls-tree`*   |                                                              | List the contents of a tree object.                          |

### M m

| *`git merge-base`*        |                                                              | Find as good common ancestors as possible for a merge.       |
| :------------------------ | :----------------------------------------------------------- | :----------------------------------------------------------- |
| *`git merge-file`*        | `-p`                                                         | Run a three-way file merge.                                  |
| *`git merge`*             | `-S` `--no-commit --no-squash --squash --verify-signatures`  | Join two or more development histories together.             |
| *`git mergetool`*         | `--tool-help`                                                | Run merge conflict resolution tools to resolve merge  conflicts. |
| *`git mv`*                |                                                              | Move or rename a file, a directory, or a symlink.            |

### P p

| *`git prune`* | `--expire`                                   | Prune all unreachable objects from the object database.      |
| :------------ | :------------------------------------------- | :----------------------------------------------------------- |
| *`git pull`*  | `--rebase --verify-signatures`               | Fetch from and integrate with another repository or a local branch. |
| *`git push`*  | `-f` `--delete --force --recurse-submodules` | Update remote refs along with associated objects.            |

### R r

| *`git read-tree`*     | `--prefix`                          |                                                        |
| :-------------------- | :---------------------------------- | :----------------------------------------------------- |
| *`git rebase`*        | `--interactive --onto`              | Reapply commits on top of another base tip.            |
| *`git reflog`*        |                                     | Manage reflog information.                             |
| *`git remote add`*    |                                     |                                                        |
| *`git remote prune`*  |                                     |                                                        |
| *`git remote pull`*   |                                     |                                                        |
| *`git remote rename`* |                                     |                                                        |
| *`git remote rm`*     |                                     |                                                        |
| *`git remote show`*   |                                     |                                                        |
| *`git remote`*        | `-v`                                | Manage set of tracked repositories.                    |
| *`git request-pull`*  |                                     | Generates a summary of pending changes                 |
| *`git reset`*         |                                     | Reset current HEAD to the specified state.             |
| *`git reset`*         | `--hard --mixed --soft`             | Reset current HEAD to the specified state.             |
| *`git rev-parse`*     |                                     | Pick out and massage parameters.                       |
| *`git revert`*        | `-m`                                | Revert some existing commits.                          |
| *`git rm`*            | `--cached --force --ignore-unmatch` | Remove files from the working tree and from the index. |

### S s

|                           |                             |                                                      |
| :------------------------ | :-------------------------- | :--------------------------------------------------- |
| *`git shortlog`*          | `--no-merges --not`         | Summarize 'git log' output.                          |
| *`git show`*              |                             | Show various types of objects.                       |
| *`git stash apply`*       |                             |                                                      |
| *`git stash branch`*      |                             |                                                      |
| *`git stash drop`*        |                             |                                                      |
| *`git stash list`*        |                             |                                                      |
| *`git stash pop`*         |                             |                                                      |
| *`git stash show`*        |                             |                                                      |
| *`git stash`*             |                             | Stash the changes in a dirty working directory away. |
| *`git stash`*             | `--keep-index`              | Stash the changes in a dirty working directory away. |
| *`git status`*            | `--status`                  | Show the working tree status.                        |
| *`git submodule add`*     |                             |                                                      |
| *`git submodule foreach`* |                             |                                                      |
| *`git submodule init`*    |                             |                                                      |
| *`git submodule update`*  | `--merge --rebase --remote` |                                                      |
| *`git submodule`*         |                             | Initialize, update or inspect submodules.            |
| *`git svn`*               |                             | The stupid content tracker.                          |

### T t

| *`git tag`*               | `-a -d -m -s`                                                | Create, list, delete or verify a tag object signed with GPG. |
| :------------------------ | :----------------------------------------------------------- | :----------------------------------------------------------- |
|                           |                                                              |                                                              |

### R r

| *`git replace`*  |      | Create, list, delete refs to replace objects.        |
| :--------------- | :--- | :--------------------------------------------------- |
| *`git rev-list`* |      | Lists commit objects in reverse chronological order. |

### S s

| *`git symbolic-ref`* |      | Read, modify and delete symbolic refs. |
| :------------------- | :--- | :------------------------------------- |
|                      |      |                                        |
|                      |      |                                        |
|                      |      |                                        |

### U u

| *`git update-index`* | `--add --cacheinfo` | Register file contents in the working tree to the index. |
| :------------------- | :------------------ | :------------------------------------------------------- |
| *`git update-ref`*   |                     | Update the object name stored in a ref safely.           |
|                      |                     |                                                          |
|                      |                     |                                                          |

### V v

| *`git verify-pack`* | `-v` | Validate packed Git archive files. |
| :------------------ | :--- | :--------------------------------- |
|                     |      |                                    |
|                     |      |                                    |
|                     |      |                                    |

