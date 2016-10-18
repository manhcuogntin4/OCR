counter = 0.0
Dir["test*.png"].each do |file|
counter += (1.0 / 26)
puts counter
system("rm lines/*")
system("./build/bin/extract #{file} lines")
`find ./lines -name '*.png' | parallel -j 8 tesseract -psm 7 {} {}`
end
#Dir["lines/*.png"].each do |file|
#	system("tesseract #{file} -psm 7 stdout")

#end
