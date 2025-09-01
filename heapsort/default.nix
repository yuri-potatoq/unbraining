{
    buildFunc ? import ../makeCDerivation.nix {
        pkgs = import <nixpkgs> {};
    }
}: buildFunc { name = "heapsort"; src = ./.; }
