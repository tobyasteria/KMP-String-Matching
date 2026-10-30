$ErrorActionPreference = "Stop"

New-Item -ItemType Directory -Force "data" | Out-Null
$sourceUrl = "https://www.gutenberg.org/cache/epub/1661/pg1661.txt"
$outputPath = "data/week3_natural_source.txt"

Invoke-WebRequest -Uri $sourceUrl -OutFile $outputPath

Write-Host "Downloaded source to $outputPath"
Write-Host "Source: The Adventures of Sherlock Holmes - Arthur Conan Doyle"
Write-Host "Project Gutenberg eBook #1661"
