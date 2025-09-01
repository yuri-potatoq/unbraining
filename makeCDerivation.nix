{
    pkgs ?  import <nixpkgs> {},
}: { 
    name, 
    src,
    deps ? with pkgs.llvmPackages_21; [ clang-tools clang ],
} : pkgs.stdenv.mkDerivation {
    pname = "${name}";
    version = "0.1.0";
    src = src;

    buildInputs = deps;

    buildPhase = ''
        clang -o ${name} main.c
    '';

    installPhase = ''
        mkdir -p $out/bin
        cp ${name} $out/bin/
    '';
}
