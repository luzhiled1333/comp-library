<!--
>>> タイトルはある程度内容に沿っていればなんでもいいです。自由につけてください。
>>>
>>> 例
>>> - fix #61
>>>   - https://github.com/luzhiled1333/comp-library/pull/62
>>> - implement bit operations
>>>   - https://github.com/luzhiled1333/comp-library/pull/105
-->

# 概要 / Overview


# 関連 issue, PR / Related issues, PRs
<!--
>>> 以下に箇条書きの形式で関連する issue, PR の番号を記載してください。
>>>
>>> 例
>>> - #5
>>>
>>> 必要なければ消しても大丈夫です
-->

- #


# TODO
<!--
>>> この項目は必要がなけれれば削除してください。
>>> 項目が不足している場合は適宜追加していただいても構いません。
-->

- [ ] 実装
- [ ] ドキュメント作成
- [ ] unit-test
- [ ] verify

# CI 関連項目
<!--
>>> 以下はリポジトリ内であればどこでも実行できるようになっていると思います。
>>> 作業用のメモとして残しておいてください。
-->

## verify-check / verify
```sh
(cd $(git rev-parse --show-toplevel) && oj-verify all)
```

## clang-format
```sh
(cd $(git rev-parse --show-toplevel) && clang-format -i $(find src/ test/ unit-test/ -name "*.hpp" -or -name "*.cpp"))
```
