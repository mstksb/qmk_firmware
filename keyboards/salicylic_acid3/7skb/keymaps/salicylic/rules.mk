TAP_DANCE_ENABLE = yes
# ディフォルト: key-downとkey-upで指定時間安定したら信号を送出
# sym_eager_pk: key-downとkey-upでその瞬間に信号送出しその後の指定時間は無視する方式
# asym_eager_defer_pk: key-downはsym_eager_pkと同じ、key-upはディフォルト方式
DEBOUNCE_TYPE = asym_eager_defer_pk

