---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: src/cpp-template/header/template-header.hpp
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-1-a.test.cpp
    title: test/aoj/itp1-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/pair-ios.hpp\"\n\nnamespace luz\
    \ {\n\n  template< typename T1, typename T2 >\n  std::ostream &operator<<(std::ostream\
    \ &os, std::pair < T1, T2 > &p) {\n    os << \"(\" << p.first << \", \" << p.second\
    \ << \")\";\n    return os;\n  }\n\n  template< typename T1, typename T2 >\n \
    \ std::istream &operator>>(std::istream &is, std::pair< T1, T2 > &p) {\n    is\
    \ >> p.first >> p.second;\n    return is;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\nnamespace luz {\n\n  template< typename T1, typename T2 >\n\
    \  std::ostream &operator<<(std::ostream &os, std::pair < T1, T2 > &p) {\n   \
    \ os << \"(\" << p.first << \", \" << p.second << \")\";\n    return os;\n  }\n\
    \n  template< typename T1, typename T2 >\n  std::istream &operator>>(std::istream\
    \ &is, std::pair< T1, T2 > &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    \  }\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/cpp-template/header/pair-ios.hpp
  requiredBy:
  - src/cpp-template/template.cpp
  - src/cpp-template/header/template-header.hpp
  timestamp: '2022-06-13 01:05:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/itp1-1-a.test.cpp
documentation_of: src/cpp-template/header/pair-ios.hpp
layout: document
redirect_from:
- /library/src/cpp-template/header/pair-ios.hpp
- /library/src/cpp-template/header/pair-ios.hpp.html
title: src/cpp-template/header/pair-ios.hpp
---
