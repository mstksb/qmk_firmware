command:
qmk compile -kb salicylic_acid3/7skb/rev1 -km mine

# フラッシュをスキップしないと docker-machineを使用するためorbstackではエラーになる
SKIP_FLASHING_SUPPORT=1 util/docker_build.sh <keyboard>:<keymap>
SKIP_FLASHING_SUPPORT=1 util/docker_build.sh salicylic_acid3/7skb/rev1:mine

