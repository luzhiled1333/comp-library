[![Actions Status](https://github.com/luzhiled1333/comp-library/workflows/verify/badge.svg)](https://github.com/luzhiled1333/comp-library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://Luzhiled1333.github.io/comp-library/)

# comp-library
## usage
TODO

## src/
TODO

## docs/
TODO

```
# path/to/comp-library/ 下
oj-verify run
oj-verify docs
```

> 1. Install Ruby with the files to build native modules. In Ubuntu, $ sudo apt install ruby-all-dev
> 2. Install Ruby's Bundler (https://bundler.io/). In Ubuntu, $ sudo apt install ruby-bundler
> 3. $ cd .verify-helper/markdown
> 4. $ bundle install --path .vendor/bundle
> 5. $ bundle exec jekyll serve --incremental
> 6. Open http://127.0.0.1:4000 on your web browser

## test/
`src/cpp-template/` 以下のファイルは最小限を include するようにする。

warning は抑制するようにする。`rep` 構造体を用いるときなどはよく unused-variable でエラーが出るので [\[\[maybe_unused\]\]属性](https://cpprefjp.github.io/lang/cpp17/maybe_unused.html) を使う。

`*.test.cpp` ファイルのテンプレート:

```cpp
// verification-helper: PROBLEM https://

namespace luz {

  void main_() {

  }

} // namespace luz

int main() {
  luz::main_();
}
```

### test/aoj
[Aizu Online Judge](https://onlinejudge.u-aizu.ac.jp/)を用いたテストをすべてここの直下に置く。

ファイル名は `問題ID + .test.cpp` とし、問題ID の英大文字は英小文字に、`_` は `-` に置き換えている。

リンクは以下の形式で統一する。

```
// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/${PROBLEM_ID}
```

### test/atcoder
URL `atcoder.jp/contests/CONTEST_ID/tasks/PROBLEM_ID` の末尾の PROBLEM_ID をテストのファイル名としている。


## unit-test/
TODO
