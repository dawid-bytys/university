export async function uploadImage(file) {
  const formData = new FormData();

  formData.append('file', file);
  formData.append('upload_preset', 'n1ar0qqe');

  const response = await fetch('https://api.cloudinary.com/v1_1/dwgdq9vdt/image/upload', {
    method: 'POST',
    body: formData,
  });

  if (!response.ok) {
    throw new Error('Error uploading image');
  }

  const cloudinaryResponse = await response.json();
  return cloudinaryResponse.secure_url;
}
