# Makefile

# === Variables ===
# Input/Output files
MARKDOWN_FILE = record.md
PDF_FILE = record.pdf

# Configuration and Tools
TEMPLATE_FILE = template.tex
FILES ?= ../.
GENERATION_SCRIPT = ./generate-markdown.sh
PANDOC_METADATA = metadata.yaml
PANDOC_HEADER_INCLUDE = deeplists.tex
PDF_VIEWER = zathura

# === Targets ===

# Default target executed when you just run 'make'
# This depends on the final PDF file. Make will resolve dependencies
# in the correct order (script first if needed, then pandoc).
all: $(PDF_FILE)

# Rule to generate the Markdown file using the script
# The target is the file that this rule *creates* ($(MARKDOWN_FILE)).
# The prerequisite is the script itself. If the script changes,
# the markdown file will be considered outdated.
$(MARKDOWN_FILE): $(GENERATION_SCRIPT)
	@echo "--- Generating Markdown file: $(MARKDOWN_FILE) using files from $(FILES) ---"
	$(GENERATION_SCRIPT) $(MARKDOWN_FILE) $(FILES)

# Rule to create the PDF file from the Markdown file
# The target is the PDF file.
# Prerequisites are all the files needed to build it. If any of these
# change (or if the target PDF doesn't exist), this rule runs.
$(PDF_FILE): $(MARKDOWN_FILE) $(TEMPLATE_FILE) $(PANDOC_METADATA) $(PANDOC_HEADER_INCLUDE)
	@echo "--- Generating PDF file: $(PDF_FILE) ---"
	pandoc \
	--output=$(PDF_FILE) \
	--standalone \
	--include-in-header=$(PANDOC_HEADER_INCLUDE) \
	--metadata-file=$(PANDOC_METADATA) \
	--template=$(TEMPLATE_FILE) \
	--from=markdown \
	--to=pdf \
	$(MARKDOWN_FILE)

# Phony target to explicitly run the markdown generation step.
# It depends on the actual file target. Running 'make markdown'
# will ensure the markdown file is up-to-date.
markdown: $(MARKDOWN_FILE)
	@echo "--- Markdown file ensured up-to-date ---"

# Phony target to explicitly run the PDF generation step.
# It depends on the actual file target. Running 'make pdf'
# will ensure the PDF file is up-to-date (running the script first if needed).
pdf: $(PDF_FILE)
	@echo "--- PDF file ensured up-to-date ---"

# Show the generated PDF file
# Depends on the PDF file existing.
show: $(PDF_FILE)
	@echo "--- Showing PDF file: $(PDF_FILE) ---"
	$(PDF_VIEWER) $(PDF_FILE) &

# Clean up generated files
clean:
	@echo "--- Cleaning generated files ---"
	rm -f $(PDF_FILE) $(MARKDOWN_FILE)

# Declare targets that do not correspond to actual files.
# This prevents issues if a file with the same name exists and
# ensures the commands always run when the target is invoked (unless prerequisites stop it).
.PHONY: all pdf markdown show clean
