import fs from 'fs';

function imageToBase64(filePath) {
  const imageBuffer = fs.readFileSync(filePath);
  const base64Image = imageBuffer.toString('base64');
  return base64Image;
}

console.log(`data:image/png;base64,${imageToBase64('./x5tb.png')}`);