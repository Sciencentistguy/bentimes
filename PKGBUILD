# Maintainer: Jamie Quigley <jamie.e.quigley@gmail.com>

pkgname=bentimes
pkgver=1.0
pkgrel=1
pkgdesc="C++ program to generate \"Ben times\""
arch=('any')
url="https://github.com/Sciencentistguy/bentimes"
license=('GPL')
groups=()
depends=()
makedepends=('git')
provides=("${pkgname%-VCS}")
conflicts=("${pkgname%-VCS}")
replaces=()
backup=()
options=()
install=
source=('git+https://github.com/Sciencentistguy/bentimes.git')
noextract=()
md5sums=('SKIP')


build() {
    cd "$srcdir/${pkgname%}"
    g++ bentimes.cpp -o bentimes
}


package() {
    mkdir -p $pkgdir/usr/bin
	cp "$srcdir/${pkgname%}"/bentimes ${pkgdir}/usr/bin
}
