---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/cpp-template/header/includes.hpp:\
    \ line -1: no such header\n"
  code: "#include <algorithm>\n#include <vector>\n\n#include \"src/cpp-template/header/includes.hpp\"\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/cpp-template/header/rep.hpp\"\
    \n\nnamespace luz {\n\n  template< typename T >\n  std::vector< usize > coordinate_compression(std::vector<\
    \ T > vs) {\n    std::vector< usize > res(vs.size());\n\n    std::vector< T >\
    \ zip = vs;\n    std::sort(zip.begin(), zip.end());\n    zip.erase(std::unique(zip.begin(),\
    \ zip.end()), zip.end());\n\n    for (usize i: rep(0, vs.size())) {\n      res[i]\
    \ = std::lower_bound(zip.begin(), zip.end(), vs[i]) - zip.begin();\n    }\n\n\
    \    return res;\n  }\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/sequence/coordinate-compression.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/sequence/coordinate-compression.hpp
layout: document
redirect_from:
- /library/src/sequence/coordinate-compression.hpp
- /library/src/sequence/coordinate-compression.hpp.html
title: src/sequence/coordinate-compression.hpp
---
