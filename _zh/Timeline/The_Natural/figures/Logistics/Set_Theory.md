
```
# 集合的运算性质
# 事件的运算性质
[空集] [𝟘 ≡ {e | e ≠ e}] ⇔ ∀e;[[e ∈ 𝟘] ↔ [e ≠ e]]
[全集] [𝟙 ≡ {e | e = e}] ⇔ ∀e;[[e ∈ 𝟙] ↔ [e = e]]

[补运算]    [¬S ≡ {e | [e ∉ S]}]            ⇔ ∀e;[[e ∈ ¬S] ↔ [e ∉ S]]
[合运算] [S ∨ T ≡ {e | [e ∈ S] ∨ [e ∈ T]}]  ⇔ ∀e;[[e ∈ S ∨ T] ↔ [[e ∈ S] ∨ [e ∈ T]]]
[交运算] [S ∧ T ≡ {e | [e ∈ S] ∧ [e ∈ T]}]  ⇔ ∀e;[[e ∈ S ∧ T] ↔ [[e ∈ S] ∧ [e ∈ T]]]
[差运算] [S ⊖ T ≡ {e | [e ∈ S] ⊖ [e ∈ T]}]  ⇔ ∀e;[[e ∈ S ⊖ T] ↔ [[e ∈ S] ⊖ [e ∈ T]]]
[对称差] [S ⊕ T ≡ {e | [e ∈ S] ⊕ [e ∈ T]}]  ⇔ ∀e;[[e ∈ S ⊕ T] ↔ [[e ∈ S] ⊕ [e ∈ T]]]
[幂运算]  [𝓟(S) ≡ {P | P ⊆ S}]              ⇔ ∀P;[[P ∈ 𝓟(S)] ↔ [P ⊆ S]]

[全等关系] [S ↔ T] ⇔ ∀e;[[e ∈ S] ↔ [e ∈ T]]
[包含关系] [S → T] ⇔ ∀e;[[e ∈ S] → [e ∈ T]]
```


```
   [S ⊂ T]
 ⇔ [S → T] ∧ ¬[S = T]
 ⇔ ∀e;[[e ∈ S] → [e ∈ T]] ∧ ¬∀e;[[e ∈ S] ↔ [e ∈ T]]
 ⇔ ∀e;[[e ∈ S] → [e ∈ T]] ∧ ¬∀e;[[[e ∈ S] → [e ∈ T]] ∧ [[e ∈ T] → [e ∈ S]]]
 ⇔ ∀e;[[e ∈ S] → [e ∈ T]] ∧ ¬[∀e;[[e ∈ S] → [e ∈ T]] ∧ ∀e[[e ∈ T] → [e ∈ S]]]
 ⇔ ∀e;[[e ∈ S] → [e ∈ T]] ∧ [¬∀e;[[e ∈ S] → [e ∈ T]] ∨ ¬∀e[[e ∈ T] → [e ∈ S]]]
 ⇔ ∀e;[[e ∈ S] → [e ∈ T]] ∧ ¬∀e;[[e ∈ T] → [e ∈ S]]
1⇔ ∀e;[[e ∈ S] → [e ∈ T]] ∧ ∃t;[¬[[t ∈ T] → [t ∈ S]]]
 ⇔ ∀e;∃t;[[[e ∈ S] → [e ∈ T]] ∧ ¬[[t ∈ T] → [t ∈ S]]]
 ⇔ ∀e;∃t;[[[e ∈ S] → [e ∈ T]] ∧ ¬[¬[t ∈ T] ∨ [t ∈ S]]]
1⇔ ∀e;∃t;[[[e ∈ S] → [e ∈ T]] ∧ [[t ∈ T] ∧ ¬[t ∈ S]]]

   [E → F] → [F ↔ F ∨ E]
 ⇒           ∀x[[x ∈ F] → [x ∈ F]]
 ⇒ [E → F] → ∀x[[x ∈ E] → [x ∈ F]]
 ⇒ [E → F] → ∀x[[x ∈ F] ∨ [x ∈ E] → [x ∈ F] ∨ [x ∈ F]]
 ⇒ [E → F] → ∀x[[x ∈ F] ∨ [x ∈ E] → [x ∈ F]]
 ⇒ [E → F] → ∀x[[x ∈ F] → [x ∈ F] ∨ [x ∈ E]]
 ⇒ [E → F] → ∀x[[x ∈ F] ↔ [x ∈ F] ∨ [x ∈ E]]
 ⇒ [E → F] → ∀x[[x ∈ F] ↔ [x ∈ F ∨ E]]
1⇒ [E → F] → [F ↔ F ∨ E]
```

于2020年08月21日 00:06:00 +08 在湛江 +08