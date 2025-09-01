{
  description = "Algos";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem
      (system:
        let
          pkgs = import nixpkgs { system = system; };

          clang-pkgs = with pkgs.llvmPackages_21; [
            clang-tools
          ];
          
          makeCDerivation = import ./makeCDerivation.nix { pkgs = pkgs; };
        in
        rec {
          devShell = pkgs.mkShell {
            nativeBuildInputs = [ pkgs.pkg-config ];
            packages = clang-pkgs;

            #CPATH = builtins.concatStringsSep ":" [
            #  (pkgs.lib.makeSearchPathOutput "dev" "include" ([ llvm.libcxx ]))
            # (pkgs.lib.makeSearchPath "resource-root/include" ([ llvm.clang ]))
            #];
          };

          packages = {
            heapsort = import ./heapsort { buildFunc = makeCDerivation; };
          };
        }
      );
}
