#!/usr/bin/env bash

# Required tools
REQUIRED_TOOLS=("pandoc" "pdflatex" "kpsewhich")

LATEX_DEPENDENCIES=(
  article.cls
  size10.clo
  amsmath.sty
  amstext.sty
  amsgen.sty
  amsbsy.sty
  amsopn.sty
  amssymb.sty
  amsfonts.sty
  iftex.sty
  fontenc.sty
  inputenc.sty
  textcomp.sty
  lmodern.sty
  upquote.sty
  microtype.sty
  keyval.sty
  etoolbox.sty
  microtype-pdftex.def
  microtype.cfg
  parskip.sty
  kvoptions.sty
  ltxcmds.sty
  kvsetkeys.sty
  xcolor.sty
  color.cfg
  pdftex.def
  mathcolor.ltx
  fancyvrb.sty
  enumitem.sty
  bookmark.sty
  hyperref.sty
  kvdefinekeys.sty
  pdfescape.sty
  pdftexcmds.sty
  infwarerr.sty
  hycolor.sty
  nameref.sty
  refcount.sty
  gettitlestring.sty
  stringenc.sty
  pd1enc.def
  intcalc.sty
  puenc.def
  url.sty
  bitset.sty
  bigintcalc.sty
  atbegshi-ltx.sty
  hpdftex.def
  atveryend-ltx.sty
  rerunfilecheck.sty
  uniquecounter.sty
  bkm-pdftex.def
  xurl.sty
  pdfpages.sty
  ifthen.sty
  calc.sty
  eso-pic.sty
  graphicx.sty
  graphics.sty
  trig.sty
  graphics.cfg
  pppdftex.def
  t1lmr.fd
  l3backend-pdftex.def
  mt-cmr.cfg
  supp-pdf.mkii
  epstopdf-base.sty
  epstopdf-sys.cfg
  pdflscape.sty
  pdflscape-nometadata.sty
  lscape.sty
  ot1lmr.fd
  omllmm.fd
  omslmsy.fd
  omxlmex.fd
  umsa.fd
  mt-msa.cfg
  umsb.fd
  mt-msb.cfg
  t1lmtt.fd
  ts1lmtt.fd
  ts1lmr.fd
)

PDF_ASSETS=(
  # Add any PDF assets you need to check here
  # Example: "path/to/asset.pdf"
  "./assets/private/cover.jpeg"
  "./assets/private/bonafide.jpeg"
  "./assets/private/index.jpeg"
  "./deeplists.tex"
  "./metadata.yaml"
  "./template.tex"
)

check_tools() {

  local IFS=" "

  local missing_tools=()
  for tool in "${REQUIRED_TOOLS[@]}"; do
    if ! command -v "$tool" &>/dev/null; then
      missing_tools+=("$tool")
    fi
  done

  if [ ${#missing_tools[@]} -ne 0 ]; then
    echo "ERROR: Required tools not found: ${missing_tools[*]}"
    echo "Install the missing tools and try again."
    exit 1
  fi

  echo "Required tools are installed"
}

check_latex_depends() {

  local IFS=" "

  local missing_tools=()
  for tool in "${LATEX_DEPENDENCIES[@]}"; do
    if ! kpsewhich "$tool" &>/dev/null; then
      missing_tools+=("$tool")
    fi
  done

  if [ ${#missing_tools[@]} -ne 0 ]; then
    echo "ERROR: Required latex files not found: ${missing_tools[*]}"
    echo "Install the missing files and try again."
    exit 1
  fi

  echo "Latex packages requirements satisfied"
}

check_pdf_assets() {

  local IFS=" "

  local missing_assets=()
  for asset in "${PDF_ASSETS[@]}"; do
    if [[ ! -f "$asset" ]]; then
      missing_assets+=("$asset")
    fi
  done

  if [ ${#missing_assets[@]} -ne 0 ]; then
    echo "ERROR: Required pdf assets not found: ${missing_assets[*]}"
    echo "Save the required assets and try again."
    exit 1
  fi

  echo "PDF assets requirements satisfied"
}

main() {
  check_tools
  check_latex_depends
  check_pdf_assets
  echo "All dependencies are installed."
}

main
