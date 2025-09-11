# Vim Setup Guide for This `.vimrc`

This document lists the packages and steps needed to use the included `.vimrc` on Linux (Debian/Ubuntu), Termux (Android), and macOS. It also calls out a couple of config gotchas and gives optional alternatives.

---

## What this `.vimrc` expects

**Plugin manager**
- [`vim-plug`](https://github.com/junegunn/vim-plug)

**Plugins used**
- `tpope/vim-sensible`
- `ycm-core/YouCompleteMe` (native completer; requires compilation)
- `hail2u/vim-css3-syntax`
- `othree/html5.vim`

**Notable settings**
- 4‑space indent defaults; 2‑space for HTML/CSS/JS
- `virtualedit=onemore` (move cursor one char past line end)
- HTML/XML tag pair matching via `matchpairs` option
- Insert‑mode <TAB> mapping currently calls `coc#refresh()` (that’s for **coc.nvim**, which is **not** actually installed by default here; see **Gotchas** below.)

---

## Prerequisites by platform

### Debian/Ubuntu (desktop/laptop, WSL, headless Debian)
```bash
sudo apt update
sudo apt install -y \
  vim git curl build-essential cmake python3 python3-dev \
  clangd # recommended for C/C++ completion backend
```
> Ensure Vim has Python 3 support (needed by YouCompleteMe):
```bash
vim --version | grep +python3
```
You should see `+python3` (not `-python3`). If not, install `vim-gtk3` or `vim-nox`:
```bash
sudo apt install -y vim-gtk3
```

### Termux on Android
```bash
pkg update
pkg install -y \
  vim git curl python cmake make clang nodejs
```
Notes:
- Termux’s `vim` usually has `+python3`, but verify with `vim --version | grep +python3`.
- Building YouCompleteMe through a Termux environment can be slow; have patience and free storage.

### macOS (optional)
```bash
# Install Homebrew if needed, then:
brew install vim git curl cmake python clangd
```
> Prefer Homebrew Vim (has `+python3`) over the system one.

---

## Install steps (all platforms)

1) **Clone/sync this repo** to each machine (e.g., `~/dotfiles`):
```bash
git clone <your-repo-url> ~/dotfiles
```

2) **Install vim‑plug**:
```bash
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
  https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
```

3) **Link or copy the `.vimrc`** from this repo to your home directory:
```bash
ln -s ~/dotfiles/.vimrc ~/.vimrc
# or copy: cp ~/dotfiles/.vimrc ~/.vimrc
```

4) **Open Vim and install plugins**:
```vim
:PlugInstall
```

5) **Build YouCompleteMe** (required!)
```bash
# from Vim, run :YcmDebugInfo to see if it’s ready; if not, build:
python3 ~/.vim/plugged/YouCompleteMe/install.py --clangd-completer
```
- If you also want extra completers (e.g., JavaScript/TypeScript), add `--ts-completer` (requires `nodejs`).
- Ensure `clangd` is installed (see prerequisites). YCM prefers to use an external `clangd`.

6) **(Optional) Provide compile flags** for accurate C/C++ completion:
- Put a `compile_commands.json` in your project root (from CMake: `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON`), or
- Add a `.ycm_extra_conf.py` at project root with include paths.

---

## Gotchas & tweaks

1) **TAB mapping references `coc#refresh()`** but `coc.nvim` is not installed here.
   - **Option A (stick with YouCompleteMe):** Change the mapping to a YCM‑friendly fallback, or remove it. Example minimal tab‑to‑next‑popup item mapping:
     ```vim
     " Simple: use built-in pum navigation only
     inoremap <expr> <Tab> pumvisible() ? "\<C-n>" : "\<Tab>"
     inoremap <expr> <S-Tab> pumvisible() ? "\<C-p>" : "\<S-Tab>"
     ```
   - **Option B (switch to coc.nvim):** Add the plugin and keep the mapping:
     ```vim
     Plug 'neoclide/coc.nvim', {'branch': 'release'}
     ```
     Then `:PlugInstall`. `coc.nvim` needs Node.js (already in Termux prereqs).

2) **`let g:loaded_matchparen = 1` actually disables the default `matchparen` plugin.**
   - That’s okay since you’re extending `matchpairs` manually for HTML/XML; just be aware you’ve opted out of the stock matchparen behavior.

3) **`set complete+=k`** augments completion with dictionary files from the `'dictionary'` option. If you don’t set `'dictionary'`, it’s harmless but unused.

4) **C/C++ headers not found in completion**
   - Install system headers/SDKs and ensure `clangd` can see them. On Debian/Ubuntu: `sudo apt install build-essential` (already above).

5) **Termux quirks**
   - On Android, long builds may be killed by low memory/storage. Close other apps and ensure sufficient free space before running the YCM installer.

---

## Quick verification checklist
- `vim --version | grep +python3` → shows `+python3`
- Inside Vim: `:PlugStatus` → all plugins are installed/updated
- `:YcmDebugInfo` → shows `clangd` running and project recognized
- For HTML/CSS/JS files: indentation is 2 spaces and tag pairs highlight
- Try cursor past end of line → works due to `virtualedit=onemore`

---

## Optional: manage dotfiles cleanly
Consider using GNU Stow to symlink manage:
```bash
sudo apt install -y stow   # or: pkg install stow (Termux)
# repo layout
# ~/dotfiles/
#   vim/.vimrc
#   ...
cd ~/dotfiles
stow -t ~ vim
```

---

## Minimal bootstrap script (copy/paste)
> **Read it first** and adjust `<your-repo-url>`.
```bash
set -e
# 1) deps
if command -v apt >/dev/null 2>&1; then
  sudo apt update
  sudo apt install -y vim git curl build-essential cmake python3 python3-dev clangd
elif command -v pkg >/dev/null 2>&1; then
  pkg update
  pkg install -y vim git curl python cmake make clang nodejs
fi
# 2) repo
[ -d ~/dotfiles ] || git clone <your-repo-url> ~/dotfiles
# 3) vim-plug
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
  https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
# 4) link
ln -sf ~/dotfiles/.vimrc ~/.vimrc
# 5) noninteractive PlugInstall (first run will still need to open Vim if headless)
vim +PlugInstall +qall || true
# 6) build YCM
python3 ~/.vim/plugged/YouCompleteMe/install.py --clangd-completer || true
```

---

## Troubleshooting quick refs
- YCM build errors → ensure `cmake`, `make`, `python3-dev`, `clangd` installed.
- No completion in C/C++ → open a file within a project root and verify `:YcmDebugInfo`; add `compile_commands.json`.
- TAB key does nothing → remove the `coc#refresh()` mapping or install `coc.nvim`.
- Want both YCM and coc.nvim? It’s possible but **not recommended**; pick one to avoid conflicts.

---

**That’s it!** This repo’s `.vimrc` should now work consistently across desktop Linux, headless Debian, Termux on Android, and macOS.
