# YouCompleteMe: a code-completion engine for Vim
- [github](https://github.com/ycm-core/YouCompleteMe)

## 설치
### [vundle](https://github.com/VundleVim/Vundle.vim) vim 플러그인 매니저

```bash
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
```

- .vimrc 최상단에 설정파일 넣기
  - 주의 : 아래 내용은 막을것. 그렇지 않을 경우 에러 발생함

```
Plugin 'file:///home/gmarik/path/to/plugin'
```

- 플러그인 설치. 두 방법 중에 하나 쓰면 됨
  - Launch vim and run :PluginInstall
  - To install from command line: vim +PluginInstall +qall

### [youcompleteme](https://vimawesome.com/plugin/youcompleteme) 설치
- [vimawesome](https://vimawesome.com) 에 가면 vundle 이용한 설치방법이 있음

```
Place this in your .vimrc:

Plugin 'valloric/youcompleteme'
… then run the following in Vim:

:source %
:PluginInstall
```

- 에러 발생. [Linux 64bit 설치방법](https://vimawesome.com/plugin/youcompleteme#linux-64-bit)

```
Install cmake, vim and python
apt install build-essential cmake vim-nox python3-dev
Install mono-complete, go, node, java and npm
apt install mono-complete golang nodejs default-jdk npm
Compile YCM
cd ~/.vim/bundle/YouCompleteMe
python3 install.py --all
```

- 다시 :PluginInstall 하면 Done! 이 뜬다.

## 사용법
- 그냥 vim 들어가서 코딩하니 잘 나오네

## 코드 컴파일
- [YouCompleteMe and CMake](https://bastian.rieck.me/blog/posts/2015/ycm_cmake/)

# vim clang
- Reference : https://vimawesome.com/plugin/vim-clang
- github : https://github.com/justmao945/vim-clang
- win10-wsl2에 기본 설치했는데 오류 발생하여 중단ㅇ

```
-- Omni 완성 (^O^N^P) 패턴을 찾을 수 없습니다
``` 

## installation
- clang install

```bash
sudo apt install clang
```

- vim 플러그인 매니저 설치
  - 뭔지 모르겠지만 일단 좋아보이므로 설치
  - pathogen 이 쉽다니 설치
    - [pathogen github](https://github.com/tpope/vim-pathogen)
  - 플러그인 매니저에 대한 자세한 내용은 [여기](https://vi.stackexchange.com/questions/388/what-is-the-difference-between-the-vim-plugin-managers)

```bash
mkdir -p ~/.vim/autoload ~/.vim/bundle && \
curl -LSso ~/.vim/autoload/pathogen.vim https://tpo.pe/pathogen.vim
```

- .vimrc 에 아래 내용 추가

```
call pathogen#infect()
call pathogen#helptags() "If you like to get crazy :)
```

- vim-clang 설치

```bash
cd ~/.vim/bundle
git clone https://github.com/justmao945/vim-clang.git
```

- .vimrc에 아래 내용 추가

```
 let g:clang_c_options = '-std=gnu11'
 let g:clang_cpp_options = '-std=c++11 -stdlib=libc++'
```
