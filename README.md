[![Actions Status](https://github.com/beet-aizu/library/workflows/verify/badge.svg)](https://github.com/beet-aizu/library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://Luzhiled.github.io/comp-library/)

# comp-library
## usage
TODO

## src/
TODO

## docs/
TODO

## test/
`src/cpp-template/` 以下のファイルは最小限を include するようにする。

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
