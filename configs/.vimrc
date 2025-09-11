set number
syntax on
filetype plugin indent on
set tabstop=4
set shiftwidth=4
set expandtab
set autoindent
set smartindent
set virtualedit=onemore
au BufNewFile,BufRead *.py set filetype=python
augroup cpp_ft
  autocmd!
  autocmd BufNewFile,BufRead *.cpp,*.h,*.hpp,*.hh,*.hxx setfiletype cpp
augroup END

" Use 2-space indentation for HTML, CSS, JS
"autocmd FileType html,css,javascript setlocal shiftwidth=2 tabstop=2 softtabstop=2
autocmd FileType html,css,javascript setlocal shiftwidth=2 tabstop=2 softtabstop=2 expandtab autoindent smartindent


" Enable keyword-based autocomplete
set complete+=k
set wildmenu
set wildmode=longest:full,full

" Highlight matching tags in HTML/XML
let g:loaded_matchparen = 1
au FileType html,xml setlocal matchpairs+=<:>

colorscheme desert

" Enables <tab> completion and suggestions
inoremap <silent><expr> <TAB>
      \ pumvisible() ? "\<C-n>" :
      \ CheckBackspace() ? "\<TAB>" :
      \ coc#refresh()

function! CheckBackspace() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction


call plug#begin()

" List your plugins here
Plug 'tpope/vim-sensible'
Plug 'ycm-core/YouCompleteMe'
Plug 'hail2u/vim-css3-syntax'
Plug 'othree/html5.vim'

call plug#end()

let g:html_indent_style1 = 'inc'
let g:html_indent_style_tag = 'noinc'
let g:html_indent_script1 = 'inc'
let g:html_indent_script_tag = 'noinc'

